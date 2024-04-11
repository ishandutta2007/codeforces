# include <iostream>
# include <cstdio>
using namespace std;
# define rep(i,n) for(int i=0;i<n;i++)
const int N = 40;
int a[N][N], b[N][N];
int ans = -0x7fffffff;
int n,m;

int abs(int x){ return x>=0?x:-x; }

void solve(int s) {
    int res = 0; // temp result;
    rep(i,n) rep(j,n) a[i][j] = b[i][j];
    rep(t,m+1) if((s>>t)&1) rep(i,m+1) rep(j,m+1) a[i][j+t] = -a[i][j+t];
    rep(i,n) res += a[m][i];
    rep(i,m) rep(j,n) a[i][j] += a[i+m+1][j];
    rep(i,m) {
        int res1 = a[i][m];
        rep(j,m) res1 += abs(a[i][j] + a[i][j+m+1]);
        int res2 = -a[i][m];
        rep(j,m) res2 += abs(a[i][j] - a[i][j+m+1]);
        res += max(res1, res2);
    } 
    if (res>ans) ans = res;
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n; m = n/2;
    rep(i,n) rep(j,n) cin>>b[i][j];
    rep(i,1<<(m+1)) solve(i);
    cout << ans << endl;
    //while(1); 
    return 0;
}