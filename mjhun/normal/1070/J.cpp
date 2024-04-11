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

#define MOD 212345678987654321LL

ll mod(ll a){return a>=MOD?a-MOD:a;}

int n,m,k;
char s[200005];
ll f[200005];
int q[32];

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%d%d%s",&n,&m,&k,s);
		mset(q,0);
		fore(i,0,k)q[s[i]-'A']++;
		f[0]=1;
		fore(i,1,k+1)f[i]=0;
		fore(i,0,26){
			if(!q[i])continue;
			for(int j=k;j>=q[i];--j)f[j]=mod(f[j]+f[j-q[i]]);
		}
		int t=n;
		while(!f[t])t++;
		if(t+m<=k){puts("0");continue;}
		t=m;
		while(!f[t])t++;
		if(t+n<=k){puts("0");continue;}
		ll r=1LL<<60;
		fore(i,0,26){
			if(!q[i])continue;
			fore(j,q[i],k+1)if(f[j-q[i]])f[j]=mod(f[j]+MOD-f[j-q[i]]);

			int t=n;
			while(!f[t])t--;
			int a=n-t;
			int b=m-(k-(t+q[i]));
			if(min(a,b)>=0&&a+b<=q[i]){
				r=min(r,1LL*a*b);
			}

			t=m;
			while(!f[t])t--;
			a=m-t;
			b=n-(k-(t+q[i]));
			if(min(a,b)>=0&&a+b<=q[i]){
				r=min(r,1LL*a*b);
			}

			for(int j=k;j>=q[i];--j)f[j]=mod(f[j]+f[j-q[i]]);
		}
		printf("%lld\n",r);
	}
	return 0;
}