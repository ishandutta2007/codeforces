#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=2005, MOD=1e9+7;
ll mem[MX][MX][2], sum[MX][MX][2];
ll nCnt[MX][MX], mCnt[MX][MX];
string g[MX];
ll n, m;

ll getAns(ll x, ll y, bool right);
ll getSum(ll x, ll y, bool right) {
    if(sum[x][y][right] == -1) {
        if(right) {
            if(x == n)
                return sum[x][y][right] = 0;
            sum[x][y][right] = (getSum(x+1,y,right)+getAns(x,y,!right))%MOD;
        } else {
            if(y == m)
                return sum[x][y][right] = 0;
            sum[x][y][right] = (getSum(x,y+1,right)+getAns(x,y,!right))%MOD;
        }
    }
    return sum[x][y][right];
}
ll getAns(ll x, ll y, bool right) {
    if(mem[x][y][right] == -1) {
        if(x+1 == n && y+1 == m) {
            return mem[x][y][right]=1;
        }
        if(right) {
            if(x + 1 == n)
                return mem[x][y][right] = 0;
            ll rocks = nCnt[x+1][y];
            ll maxRight = n-x-rocks-1;
            mem[x][y][right] = (getSum(x+1,y,right)-getSum(x+maxRight+1,y,right)+MOD)%MOD;
        } else {
            if(y + 1 == m)
                return mem[x][y][right] = 0;
            ll rocks = mCnt[x][y+1];
            ll maxDown = m-y-rocks-1;
            mem[x][y][right] = (getSum(x,y+1,right)-getSum(x,y+maxDown+1,right)+MOD)%MOD;
        }
    }
    return mem[x][y][right];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(i,n) cin>>g[i];
    REV(i,0,n) {
        REV(j,0,m) {
            if(j == m-1) {
                mCnt[i][j] = g[i][j]=='R';
            } else {
                mCnt[i][j] = mCnt[i][j+1] + int(g[i][j]=='R');
            }
            if(i == n-1) {
                nCnt[i][j] = g[i][j]=='R';
            } else {
                nCnt[i][j] = nCnt[i+1][j] + int(g[i][j]=='R');
            }
        }
    }
    RE(i,n+1) RE(j,m+1) RE(k,2) mem[i][j][k] = sum[i][j][k] = -1;
    if(n == 1 && m == 1) {
        cout<<1<<endl;
    } else {
        cout<<(getAns(0,0,0)+getAns(0,0,1))%MOD<<endl;
    }
}