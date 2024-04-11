#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

int m;
#define MOD (m)
int add(int a,int b){return a+b<MOD?a+b:a+b-MOD;}
void dadd(int &a,int b){a=add(a,b);}
int sub(int a,int b){return a>=b?a-b:a-b+MOD;}
void dsub(int &a,int b){a=sub(a,b);}
int mul(int a,int b){return (LL)a*b%MOD;}
void dmul(int &a,int b){a=mul(a,b);}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)dmul(ans,a);
		b>>=1;
		dmul(a,a);
	}
	return ans;
}
int inv(int a){return ksm(a,MOD-2);}

int ceil(int a,int b){return (a-1)/b+1;}

const int N=202;
const int K=25;

int n;

int fr[N];
int ifr[N];
void init(){
	F(i,0,n)fr[i]=i?mul(fr[i-1],i):1;
	F(i,0,n)ifr[i]=inv(fr[i]);
}

bool done[K][N][K*(N+1)];
int dp[K][N][K*(N+1)];
int dfs(int a1,int x,int mn,int s){
	if(x==n)return fr[n];
	if(mn>n+1)return 0;
	if(a1*(n+1)<s+mn*(n-x))return 0;
	bool &ok=done[n+1-mn][x][x*(n+1)-s];
	int &aans=dp[n+1-mn][x][x*(n+1)-s];
	if(ok)return aans;
	int ans=0;
	ok=true;
	if(x==0){
		int t=s;
		F(y,x+1,n){
			t+=a1;
			if(t>a1*a1)break;
			// cerr<<a1<<" "<<x<<" "<<mn<<" "<<s<<" ["<<v<<" "<<y<<"] "<<y<<" "<<v+1<<" "<<t<<endl;
			dadd(ans,mul(ifr[y-x],dfs(a1,y,a1+1,t)));
		}
	}
	else{
		F(v,mn,n+1){
			int t=s;
			F(y,x+1,n){
				t+=v;
				if(t>a1*v)break;
				// cerr<<a1<<" "<<x<<" "<<mn<<" "<<s<<" ["<<v<<" "<<y<<"] "<<y<<" "<<v+1<<" "<<t<<endl;
				dadd(ans,mul(ifr[y-x],dfs(a1,y,v+1,t)));
			}
		}
	}
	aans=ans;
	return ans;
}

int calc(int a1){
	memset(done,false,sizeof(done));
	return dfs(a1,0,a1,0);
}

bool check(int a1){
	int ax=a1;
	int sum=a1;
	F(k,2,n){
		while(a1*ax<sum+ax&&ax<=n+1)ax++;
		sum+=ax;
	}
	return ax<=n+1;
}

int main(){
	n=read();
	m=read();
	init();
	int ans=0;
	F(j,1,n+1)if(check(j))dadd(ans,calc(j));
	printf("%d\n",ans);
	return 0;
}