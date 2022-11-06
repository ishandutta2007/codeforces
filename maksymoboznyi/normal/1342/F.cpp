#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 15;

vector<int> sub[(1 << N)];
int n, a[N], sum[(1 << N)], dp[N + 1][N + 1][(1 << N)], from_i[N][N + 1][(1 << N)], from[N][N + 1][(1 << N)], fst[N][N + 1][(1 << N)];
int lst_1[(1 << N)];

void get_sub(int id, int mask, int submask) {
    if (id == N) {
        sub[mask].pb(submask);
        return;
    }
    get_sub(id + 1, (mask << 1) | 1, (submask << 1));
    get_sub(id + 1, (mask << 1) | 1, (submask << 1) | 1);
    get_sub(id + 1, (mask << 1), (submask << 1));
}

vector<int> del;
vector<pair<int, int> > ans;

void go(int i, int l, int mask) {
    //cout << dp[i][l][mask] << endl;
    //cout << i << ' ' << l << ' ' << mask << ' ' << from[i][l][mask] << ' ' << fst[i][l][mask] << endl;
    if (from[i][l][mask] > 0)
        go(from_i[i][l][mask], l - 1, mask ^ from[i][l][mask]);
    int p = fst[i][l][mask];
    if (from[i][l][mask] == -1)
        return;

    for (int pos = 0; pos < n; pos++)
        if ((from[i][l][mask] >> pos) & 1)
            if (pos != p){
                int to = p, from = pos;
                for (auto q: del) {
                    if (q < p)
                        to--;
                    if (q < pos)
                        from--;
                }
                //cout << l << ' ' << pos << '*' << endl;
                ans.pb({from, to});
                del.pb(pos);
            }
}

int main()
{
    get_sub(0, 0, 0);
    for (int mask = 0; mask < (1 << N); mask++) {
        lst_1[mask] = -1;
        for (int i = 0; i < N; i++)
            if ((mask >> i) & 1){
                lst_1[mask] = i;
                break;
            }
        //cout << mask << ' ' << lst_1[mask] << endl;
    }
    int o;
    cin >> o;
    while (o--) {
        ans.clear();
        del.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            for (int l = 1; l <= n; l++)
                for (int mask = 0; mask < (1 << n); mask++)
                    dp[i][l][mask] = -1, from[i][l][mask] = -1;
        for (int mask = 0; mask < (1 << n); mask++) {
            sum[mask] = 0;
            for (int i = 0; i < n; i++)
                if ((mask >> i) & 1)
                    sum[mask] += a[i];
            if (mask != 0)
                dp[lst_1[mask]][1][mask] = sum[mask], from[lst_1[mask]][1][mask] = mask, fst[lst_1[mask]][1][mask] = lst_1[mask];
        }
        int all = (1 << n) - 1;
        for (int i = 0; i + 1 < n; i++)
            for (int l = 1; l <= n; l++)
                for (int mask = 0; mask < (1 << n); mask++)
                    if (dp[i][l][mask] != -1) {
                    //cout << sub[all ^ mask].size() << endl;
                    for (auto submask: sub[all ^ mask]) {
                        int tmp = all - ((1 << (i + 1)) - 1);
                        tmp &= submask;
                        int pos = lst_1[tmp];
                        if (pos == -1)
                            continue;
                    //    cout << i << ' ' << l << ' ' << mask << ' ' << dp[i][l][mask] << ' ' << pos << ' ' << submask << endl;
                        if (sum[submask] > dp[i][l][mask] && (dp[pos][l + 1][mask ^ submask] == -1 || dp[pos][l + 1][mask ^ submask] > sum[submask]))
                            dp[pos][l + 1][mask ^ submask] = sum[submask], from_i[pos][l + 1][mask ^ submask] = i, from[pos][l + 1][mask ^ submask] = submask, fst[pos][l + 1][mask ^ submask] = pos;

                    }
                    }
        bool can = 1;
        for (int l = n; l >= 0 && can; l--)
            for (int i = 0; i < n && can; i++)
                if (dp[i][l][all] != -1) {
                    cout << n - l << "\n";
                    go(i, l, all);
                    can = 0;
                    for (auto p: ans)
                        cout << p.first + 1 << ' ' << p.second + 1 << "\n";
                }
        //cout << "\n\n\n";
    }
    return 0;
}