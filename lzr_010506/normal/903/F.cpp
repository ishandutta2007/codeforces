#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int N = 1005;
const int MSK = (1 << 3) + 1;
const int D = 8;
char str[6][N];
int dp[N][MSK][MSK][MSK][MSK];
int n , a1 , a2 , a3 , a4;

vector<int> create(int idx ,int mr0 , int mr1 , int mr2 , int mr3)
{
    if(str[0][idx] == '.')mr0 |= 4;
    if(str[1][idx] == '.')mr1 |= 4;
    if(str[2][idx] == '.')mr2 |= 4;
    if(str[3][idx] == '.')mr3 |= 4;
    vector<int> m;
    m.pb(mr0);
    m.pb(mr1);
    m.pb(mr2);
    m.pb(mr3);
    return m;
}

int solve(int idx , int mr0 , int mr1 , int mr2 , int mr3)
{
    if(idx == n) return 0;
    int &ret = dp[idx][mr0][mr1][mr2][mr3];
    if(~ret) return ret;
    ret = solve(idx + 1, 7, 7, 7, 7) + a4;
    vector<int> m = create(idx,mr0,mr1,mr2,mr3);
    mr0 = m[0];
    mr1 = m[1];
    mr2 = m[2];
    mr3 = m[3];
    int cnt = 0;
   	rep(i, 0, 3)
        if(str[i][idx] == '*')
            if(!(m[i] & 4))cnt ++;
    ret = min(ret , solve(idx+1,((mr0*2)&7),((mr1*2)&7),((mr2*2)&7),((mr3*2)&7)) + cnt * a1);
    if((m[2]&4) && (m[3]&4)) ret = min(ret , solve(idx+1,((mr0*2)&7)|4,((mr1*2)&7)|4,((mr2*2)&7),((mr3*2)&7)) + a2);
    if((m[2]&4) || (m[3]&4)) ret = min(ret , solve(idx+1,((mr0*2)&7)|4,((mr1*2)&7)|4,((mr2*2)&7),((mr3*2)&7)) + a2 + a1);
    ret = min(ret , solve(idx+1,((mr0*2)&7)|4,((mr1*2)&7)|4,((mr2*2)&7),((mr3*2)&7)) + a2 + a1 + a1);
    if((m[0]&4) && (m[1]&4)) ret = min(ret , solve(idx+1,((mr0*2)&7),((mr1*2)&7),((mr2*2)&7)|4,((mr3*2)&7)|4) + a2);
    if((m[0]&4) || (m[1]&4)) ret = min(ret , solve(idx+1,((mr0*2)&7),((mr1*2)&7),((mr2*2)&7)|4,((mr3*2)&7)|4) + a2 + a1);
    ret = min(ret , solve(idx+1,((mr0*2)&7),((mr1*2)&7),((mr2*2)&7)|4,((mr3*2)&7)|4) + a2 + a1 + a1);
    if((m[0]&4) && (m[3]&4)) ret = min(ret , solve(idx+1,((mr0*2)&7),((mr1*2)&7)|4,((mr2*2)&7)|4,((mr3*2)&7)) + a2);
    if((m[0]&4) || (m[3]&4))  ret = min(ret , solve(idx+1,((mr0*2)&7),((mr1*2)&7)|4,((mr2*2)&7)|4,((mr3*2)&7)) + a2 + a1);
    ret = min(ret , solve(idx+1,((mr0*2)&7),((mr1*2)&7)|4,((mr2*2)&7)|4,((mr3*2)&7)) + a2 + a1 + a1);
    ret = min(ret , solve(idx+1,((mr0*2)&7)|4,((mr1*2)&7)|4,((mr2*2)&7)|4,((mr3*2)&7)|4) + a2 + a2);
    if((m[3]&4)) ret = min(ret , solve(idx+1,((mr0*2)&7)|6,((mr1*2)&7)|6,((mr2*2)&7)|6,((mr3*2)&7)) + a3);
    ret = min(ret , solve(idx+1,((mr0*2)&7)|6,((mr1*2)&7)|6,((mr2*2)&7)|6,((mr3*2)&7)|4) + a3 + a2);
    ret = min(ret , solve(idx+1,((mr0*2)&7)|6,((mr1*2)&7)|6,((mr2*2)&7)|6,((mr3*2)&7)) + a3 + a1);
    if((m[0] & 4)) ret = min(ret , solve(idx+1,((mr0*2)&7),((mr1*2)&7)|6,((mr2*2)&7)|6,((mr3*2)&7)|6) + a3);
    ret = min(ret , solve(idx+1,((mr0*2)&7)|4,((mr1*2)&7)|6,((mr2*2)&7)|6,((mr3*2)&7)|6) + a3 + a2);
    ret = min(ret , solve(idx+1,((mr0*2)&7),((mr1*2)&7)|6,((mr2*2)&7)|6,((mr3*2)&7)|6) + a3 + a1);
    ret = min(ret , solve(idx+1,((mr0*2)&7)|6,((mr1*2)&7)|6,((mr2*2)&7)|6,((mr3*2)&7)|6) + a3 + a3);
    return ret;
}

int main()
{
	n = read();
	a1 = read();
	a2 = read();
	a3 = read();
	a4 = read();
    rep(i, 0, n - 1)
        scanf("%s",str[i]);
    memset(dp,-1,sizeof dp);
    printf("%d\n",solve(0,0,0,0,0));

    return 0;
}