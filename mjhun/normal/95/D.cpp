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

#define MOD 1000000007

int tn,k;
int dp[1024][1024];
int p10[1024];
char s[1024],t[1024];int ns,nt;

int f(int i, int j){
	int& r=dp[i][j];
	if(r>=0)return r;
	if(i==0)r=0;
	else {
		r=8LL*f(i-1,min(j+1,1005))%MOD;
		if(j<=k)r+=2LL*p10[i-1]%MOD,r%=MOD;
		else r+=2LL*f(i-1,1)%MOD,r%=MOD;
	}
	return r;
}

int doit(char *s){
	int r=0,d=1005;bool c=false;
	for(int i=1005;i>=0;--i){
		fore(j,0,s[i]){
			if(!c){
				if(j==4||j==7){
					if(d<=k)r+=p10[i];
					else r+=f(i,1);
				}
				else r+=f(i,min(d+1,1005));
			}
			else {
				r+=p10[i];
			}
			r%=MOD;
		}
		if(!c&&(s[i]==4||s[i]==7)){
			if(d<=k)c=true;
			else d=0;
		}
		d=min(d+1,1005);
	}
	return r;
}

int main(){
	mset(dp,-1);
	p10[0]=1;
	fore(i,1,1024)p10[i]=10LL*p10[i-1]%MOD;
	scanf("%d%d",&tn,&k);
	while(tn--){
		mset(s,0);mset(t,0);
		scanf("%s%s",s,t);ns=strlen(s);nt=strlen(t);
		fore(i,0,ns)s[i]-='0';
		fore(i,0,nt)t[i]-='0';
		reverse(s,s+ns);reverse(t,t+nt);
		int k=0;
		while(t[k]==9)t[k++]=0;
		t[k]++;
		printf("%d\n",(doit(t)-doit(s)+MOD)%MOD);
	}
	return 0;
}