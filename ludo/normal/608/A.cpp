#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 100

int n, s;

pii prs[MAXN];

int main()
{
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;
//        cin >> prs[i].second >> prs[i].first;
//        ans = max(ans, prs[i].second + prs[i].first);
        int wait = max(0, t - (s - f));
        ans = max(ans, s + wait);
    }
    cout << ans << endl;
//    sort(prs, prs + n);
}