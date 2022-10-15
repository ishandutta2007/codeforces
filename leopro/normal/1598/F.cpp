// Not my code: https://codeforces.com/blog/entry/95856

# include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;
const int N = 4e5 + 5;
int  n,cnt[N],mnval[23][N],idx,bal,dp[1000005],prbal,winaraod,anss,ans,idd;
string s[N];
int pr[25][N];
vector < pair<int, int> > v[21][2*N];
int &cntAt(int i){
    if (i < 0 || i >= N) {
        cout << "Out of bounds";
        exit(0);
    }
    return cnt[i];
}
main() {
    std::ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>s[i];
        cntAt(i) = s[i].size();
        s[i] = "@" +s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cntAt(i); j++) {
            pr[i][j] = pr[i][j-1] + ((s[i][j]=='(') ? 1 : -1);
            winaraod = v[i][pr[i][j]+N].size();
            v[i][pr[i][j]+N].pb({j,winaraod + 1});
            mnval[i][j] = min(mnval[i][j-1], pr[i][j]);
        }
    }
    for (int i = 1; i < (1<<n); i++) {
        dp[i] = -1e9;
        bal = 0;
        for (int j = 0; j < n; j++) {
            idx = j + 1;
            if ((1<<j) & i)  bal += pr[idx][cntAt(idx)];
        }
        for (int j = 0; j < n; j++) {
            idx = j + 1;
            if ((1<<j) & i) {
                if (dp[i^(1<<j)] < 0) continue;
                prbal = bal - pr[idx][cntAt(idx)];
                if (prbal < 0) continue;
                if (prbal + mnval[idx][cntAt(idx)] >= 0)
                    dp[i] = max(dp[i], dp[i ^ (1<<j)] + (int)v[idx][-prbal + N].size()),ans = max(ans,dp[i]);
                else {
                    int le = 0;
                    int ri = (int)v[idx][-prbal + N].size() - 1;
                    anss = -1;
                    while (le <= ri) {
                        int mid = (le + ri) / 2;
                        idd = v[idx][-prbal + N][mid].f;
                        if (mnval[idx][idd] < -prbal) {
                            ri = mid - 1;
                        } else {
                            le = mid + 1;
                            anss = mid + 1;
                        }
                    }
                    if (anss == -1) continue;
                    ans = max(ans,dp[i ^ (1<<j)] + anss);
                }
            }
        }
    }
    cout<<ans<<endl;
}