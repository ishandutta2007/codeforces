#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

const int N=105;
char g[N][N], g2[N][N];
char ans[N][N];
int n;

int main(){
	cin >> n;
	fore(x,0,N)fore(y,0,N)ans[x][y]='x',g2[x][y]='.';
	ans[n-1][n-1]='o';
	fore(x,0,n)fore(y,0,n)cin>>g[x][y];
	fore(a,0,n)fore(b,0,n)if(g[a][b]=='o'){
		fore(x,0,n)fore(y,0,n)if(g[x][y]=='.'){
			int dx=x-a, dy=y-b;
			ans[n-1+dx][n-1+dy]='.';
		}
	}

	bool can = 1;
	fore(x,0,n)fore(y,0,n)if(g[x][y]=='o'){
		fore(a,0,2*n-1)fore(b,0,2*n-1)if(ans[a][b]=='x'){
			int dx=a-(n-1), dy=b-(n-1);
			int xn=dx+x, yn=dy+y;
			if(xn>=0&&xn<n&&yn>=0&&yn<n&&g[xn][yn]!='o'){
				g2[xn][yn]='x';
			}
		}
		g2[x][y]='o';
	}

	fore(x,0,n)fore(y,0,n)can&=g[x][y]==g2[x][y];
	if(can){
		cout << "YES\n";
		fore(x,0,2*n-1){
			fore(y,0,2*n-1)cout<<ans[x][y];
			cout << "\n";
		}
	}else cout << "NO\n";
	return 0;
}