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

#define MOD 1071251227
#define P 12721

char s[1<<20],t[256];int n,m,k,a,b,d;
int hs[1<<20],ht[512];
bool vis[2048][256];
char c[2048],r[2048];bool rr;

bool dfs(int i, int j){
	if(vis[i][j])return false;
	vis[i][j]=true;
	if(i==n%k){
		if(j!=b)return false;
	}
	if(i==k)return j==d;
	c[i]='0';
	if(dfs(i+1,j))return true;
	if(j<d&&hs[i]==ht[j]){
		c[i]='1';
		if(dfs(i+1,j+1))return true;
	}
	return false;
}

int main(){
	gets(s);gets(t);
	scanf("%d",&k);n=strlen(s);m=strlen(t);a=n/k;
	if(n>400000){puts("0");return 0;}
	for(int i=n-1;i>=0;--i)hs[i]=(1LL*P*hs[i+k]+s[i])%MOD;
	fore(_d,1,201){d=_d;
		b=m-d*a;
		if(b<0||b>min(n%k,d))continue;
		for(int i=m-1;i>=0;--i)ht[i]=(1LL*P*ht[i+d]+t[i])%MOD;
		mset(vis,false);
		if(dfs(0,0)){
			if(!rr||strncmp(c,r,k)<0)mcopy(r,c);
			rr=true;
		}
	}
	if(!rr)puts("0");
	else puts(r);
	return 0;
}