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
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n;
int g[16][16];
vector<vector<int> > s;
int c[16];
vector<int> gg[16];
bool v[16];
vector<int> t;

void dfs(int x){
	if(v[x])return;
	v[x]=true;
	for(int y:gg[x])dfs(y);
	t.pb(x);
}

char r[3][32][32];

void setp(int i, int j){
	r[0][i][j]='#';
	r[1][i][j]=r[2][i][j]='.';
}

void setx(int i, int j){
	r[0][i][j]=r[1][i][j]=r[2][i][j]='#';
}

void sete(int i, int j){
	r[0][i][j]=r[1][i][j]=r[2][i][j]='.';
}

bool asd(int i, int j){
	if(i==j)return true;
	for(int k:gg[i])if(k==j)return true;
	return false;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)fore(j,0,n)scanf("%d",&g[i][j]);
	fore(i,0,n)g[i][i]=1;
	fore(k,0,n)fore(i,0,n)fore(j,0,n)g[i][j]|=g[i][k]&g[k][j];
	mset(c,-1);
	fore(i,0,n)if(c[i]<0){
		vector<int> w;
		fore(j,0,n)if(g[i][j]&&g[j][i])c[j]=SZ(s),w.pb(j);
		s.pb(w);
	}
	fore(i,0,n)fore(j,0,n)if(c[i]!=c[j]&&g[i][j])gg[c[i]].pb(c[j]);
	fore(i,0,SZ(s))dfs(i);
	reverse(t.begin(),t.end());
	printf("%d %d %d\n",3,2*n,3*SZ(t));
	bool pingo=false;
	for(int k:t){
		// col 0
		fore(i,0,2*n)setp(i,0);
		for(int i:s[k])r[1][i][0]='1'+i;
		// col 1
		fore(i,0,2*n){
			if(i%2==0){
				if(asd(k,i/2))setp(i,1);
				else setx(i,1);
			}
			else {
				setx(i,1);
			}
		}
		// col 2
		fore(i,0,2*n){
			if(i%2==1)setx(i,2);
			else if(i/2==k)setp(i,2);
			else sete(i,2);
		}
		for(int i=2;i>=0;--i){
			if(pingo)puts("");
			pingo=true;
			fore(j,0,2*n)puts(r[i][j]);
		}
	}
	return 0;
}