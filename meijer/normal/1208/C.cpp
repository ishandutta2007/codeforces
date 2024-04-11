#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 2000;

int n, c;
int grid[MX][MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    c = n/2;
    REP(i,0,c) {
        REP(j,0,c) {
            grid[i][j] = grid[i+c][j] = grid[i][j+c] = grid[i+c][j+c] = (i+j*c)<<2;
            grid[i  ][j  ] |= 1;
            grid[i  ][j+c] |= 2;
            grid[i+c][j  ] |= 3;
        }
    }
    REP(i,0,n) {
        cout<<grid[i][0];
        REP(j,1,n)
            cout<<" "<<grid[i][j];
        cout<<endl;
    }
}