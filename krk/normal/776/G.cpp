#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 16;
const int Maxn = 17;
const int Maxk = 5;

char tmp[Maxn];
ll dp0[Maxd][Maxd][Maxd][Maxd][Maxd];
ll dp1[Maxd][Maxd][Maxd][Maxd];
ll dp2[Maxd][Maxd][Maxd];
ll dp3[Maxd][Maxd];
ll dp[Maxn][Maxd];
int cons[Maxk];
int T;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

void Construct(int lvl, int mx, int val)
{
    if (lvl >= Maxk) {
        if (val & 1 << mx) {
            dp[4][cons[0]]++;
            dp3[cons[0]][cons[1]]++;
            dp2[cons[0]][cons[1]][cons[2]]++;
            dp1[cons[0]][cons[1]][cons[2]][cons[3]]++;
            dp0[cons[0]][cons[1]][cons[2]][cons[3]][cons[4]]++;
        } 
        return;
    }
    for (cons[lvl] = 0; cons[lvl] < Maxd; cons[lvl]++)
        Construct(lvl + 1, max(mx, cons[lvl]), val * Maxd + cons[lvl]);
}

int getDig(char d)
{
    return isdigit(d)? d - '0': 10 + (d - 'a');
}

ll Solve(const string &rig, bool inc)
{
    deque <int> D;
    for (int i = 0; i < rig.length(); i++)
        D.push_back(getDig(rig[i]));
    while (D.size() < Maxk)
        D.push_front(0);
    ll res = 0;
    int mx = 0;
    while (D.size() > 4) {
        int d = D.front(); D.pop_front();
        for (int i = 0; i < d; i++)
            res += dp[D.size()][max(mx, i)];
        mx = max(mx, d);
    }
    vector <int> seq; seq.push_back(mx);
    int d = D.front(); D.pop_front();
    for (int i = 0; i < d; i++)
        res += dp3[seq[0]][i];
    seq.push_back(d);
    d = D.front(); D.pop_front();
    for (int i = 0; i < d; i++)
        res += dp2[seq[0]][seq[1]][i];
    seq.push_back(d);
    d = D.front(); D.pop_front();
    for (int i = 0; i < d; i++)
        res += dp1[seq[0]][seq[1]][seq[2]][i];
    seq.push_back(d);
    d = D.front(); D.pop_front();
    for (int i = 0; i < d; i++)
        res += dp0[seq[0]][seq[1]][seq[2]][seq[3]][i];
    seq.push_back(d);
    if (inc) res += dp0[seq[0]][seq[1]][seq[2]][seq[3]][seq[4]];
    return res;
}

int main()
{
    Construct(0, 0, 0);
    for (int i = 5; i < Maxn; i++)
        for (int j = 0; j < Maxd; j++)
            for (int d = 0; d < Maxd; d++)
                dp[i][j] += dp[i - 1][max(j, d)];
    scanf("%d", &T);
    while (T--) {
        string lef, rig;
        Read(lef);
        Read(rig);
        printf("%I64d\n", Solve(rig, true) - Solve(lef, false));
    }
    return 0;
}