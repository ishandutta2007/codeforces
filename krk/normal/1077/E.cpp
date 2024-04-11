#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
map <int, int> M;
vector <int> seq;
int ans;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        M[a]++;
    }
    for (map <int, int>::iterator it = M.begin(); it != M.end(); it++)
        seq.push_back(it->second);
    sort(seq.begin(), seq.end());
    for (int i = 1; i <= n; i++) {
        int res = 0;
        int ind = 0;
        for (int j = i; j <= n; j *= 2) {
            ind = lower_bound(seq.begin() + ind, seq.end(), j) - seq.begin();
            if (ind == seq.size()) break;
            res += j; ind++;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}