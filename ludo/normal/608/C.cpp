#include<algorithm>
#include<iostream>
#include<utility>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 100000
int n;
pii pr[MAXN];
int destroyed[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pr[i].first >> pr[i].second;
    }
    sort(pr, pr + n);

    int ans = MAXN + 1;
    for (int i = 0; i < n; i++) {
        int upto = pr[i].first - pr[i].second;
        int idx = lower_bound(pr, pr + n, pii(upto, 0)) - pr;
        int dest = i - idx;

        destroyed[i] = (idx == 0 ? 0 : destroyed[idx - 1]) + dest;

        int alt_ans = destroyed[i] + n - 1 - i;
        ans = min(ans, alt_ans);
    }
    cout << ans << endl;
    return 0;
}