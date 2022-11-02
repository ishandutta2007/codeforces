# include <iostream>
# include <cstdio>
# include <vector>
# include <cmath>
using namespace std;

const int MOD = 1000000007;
vector<vector<vector<int> > >f;
void add(int &x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
}


int main() {
    int n, m, x;
    cin >> n >> m >> x; x = x - 1;
    if ( n > m ) return cout<<0<<endl, 0;
    
    f.assign(m+1, vector<vector<int> > (n+1, vector<int>(n+1, 0)));
    
    f[0][0][0] = 1;
    for(int i=0; i<m; i++)
        for(int j=0; j<=n; j++)
            for(int k=0; k<=j; k++) {
                int t = f[i][j][k];
                if(!t) continue;
                if(i!=x) {
                    add(f[i+1][j][k],t);
                    if(j>k)add(f[i+1][j][k+1],t);
                }
                if(j<n) {
                    add(f[i+1][j+1][k],t);
                    add(f[i+1][j+1][k+1],t);
                }
            }
    long long ans = f[m][n][n];
    for(int i=2; i<=n; i++) ans=ans*i%MOD;
    
    cout << ans << endl;
    return 0;
}