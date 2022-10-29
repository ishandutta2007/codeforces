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

vector<int> kmppre(string& t){
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}

int n,m;
char _s[64];string t;
int x[64];
int a[64][2];
vector<int> b;

ll dp[64][64][64][2];

ll f(int kk, int i, int j, int b){
	ll& r=dp[kk][i][j][b];
	if(r>=0)return r;
	if(i==n)return r=kk==j&&b;
	r=0;
	fore(d,0,2){
		r+=f(kk,i+1,a[j][d],b||a[j][d]==m);
	}
	return r;
}

int main(){
	scanf("%d%s",&n,_s);t=string(_s);m=SZ(t);
	fore(i,0,m)x[i]=t[i]-'0';
	b=kmppre(t);
	a[0][x[0]]=1;
	a[0][x[0]^1]=0;
	fore(i,1,m){
		a[i][x[i]]=i+1;
		a[i][x[i]^1]=a[b[i]][x[i]^1];
	}
	a[m][0]=a[b[m]][0];a[m][1]=a[b[m]][1];
	mset(dp,-1);
	ll r=0;
	fore(i,0,m+1)r+=f(i,0,i,0);
	printf("%lld\n",r);
	return 0;
}