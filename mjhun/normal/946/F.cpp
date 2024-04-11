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
#define SZ(x) ((int)x.size())
#define MOD 1000000007
using namespace std;
typedef long long ll;

vector<int> kmp(string t){
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}

int xx,n;
vector<int> b;
char s[128];
int t[128][2];
int c[128][2];
int f[128][128][128];
int g[128][128][128];

int main(){
	scanf("%d%d%s",&n,&xx,s);
	b=kmp(string(s));
	if(n>1){
		t[0][0]=s[0]=='0';
		t[0][1]=s[0]=='1';
	}
	c[n-1][s[n-1]-'0']=1;
	fore(i,1,n){
		fore(j,0,2){
			if(s[i]-'0'==j){
				t[i][j]=i+1;
				if(t[i][j]==n)t[i][j]=b[n];
			}
			else {
				t[i][j]=t[b[i]][j];
			}
		}
	}
	fore(k,0,2)fore(i,0,n)fore(j,0,n){
		f[k][i][j]=t[i][k]==j;
		f[k][i][j]+=i==j;
		g[k][i][j]=t[i][k]==j&&c[i][k];
	}
	fore(k,2,xx+1)fore(i,0,n)fore(j,0,n){
		fore(l,0,n){
			f[k][i][j]+=(1LL*f[k-1][i][l]*f[k-2][l][j])%MOD;f[k][i][j]%=MOD;
			g[k][i][j]+=(1LL*g[k-1][i][l]*f[k-2][l][j]+1LL*f[k-1][i][l]*g[k-2][l][j])%MOD;g[k][i][j]%=MOD;
		}
	}
	int r=0;
	fore(i,0,n)r+=g[xx][0][i],r%=MOD;
	printf("%d\n",r);
	return 0;
}