#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x,v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define rrep(i,a,b) for(int i = b; i --> a;)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 205;

bool dp[4][4][N][N] = {};
int lastl[4][4][N][N], lastr[4][4][N][N];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	//preprocessing
	dp[0][0][0][0] = 1;
    for(int si=0; si<3; ++si) for(int sj=0; sj<3; ++sj) {
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) if(dp[si][sj][i][j]) {
            int fin = (si+sj==4) ? 15 : 25;
            if(j+fin<N) for(int k=0; i+k<N && j+k+2<N; ++k) {
                int fin2 = max(fin, k+2);
                dp[si][sj+1][i+k][j+fin2] = 1;
                lastl[si][sj+1][i+k][j+fin2] = k;
                lastr[si][sj+1][i+k][j+fin2] = fin2;
            }
            if(i+fin<N) for(int k=0; j+k<N && i+k+2<N; ++k) {
                int fin2 = max(fin, k+2);
                dp[si+1][sj][i+fin2][j+k] = 1;
                lastl[si+1][sj][i+fin2][j+k] = fin2;
                lastr[si+1][sj][i+fin2][j+k] = k;
            }
        }
    }

	int n;
	cin >> n;
	while(n--)
    {
        int a, b;
        cin >> a >> b;
        int maxd = -5;
        for(int i=0; i<=3; ++i) for(int j=0; j<=3; ++j) if(max(i, j)==3) {
            if(dp[i][j][a][b]) maxd = max(maxd, i-j);
        }
        if(maxd==-5) {
            cout << "Impossible\n";
        } else {
            int si, sj;
            if(maxd>0) {
                si = 3; sj = 3-maxd;
            }
            else {
                si = 3+maxd; sj = 3;
            }
            cout << si << ":" << sj << "\n";
            vector<int> sca, scb;
            while(a+b>0) {
                int l = lastl[si][sj][a][b];
                int r = lastr[si][sj][a][b];
                a -= l; b -= r;
                if(l>r) --si; else --sj;
                sca.push_back(l); scb.push_back(r);
            }
            for(int i=sz(sca)-1; i>=0; --i) cout << sca[i] << ":" << scb[i] << " ";
            cout << "\n";
        }
    }
}