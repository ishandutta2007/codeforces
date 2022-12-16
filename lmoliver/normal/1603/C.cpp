#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int MOD=998244353;
int add(int a,int b){return a+b<MOD?a+b:a+b-MOD;}
void dadd(int &a,int b){a=add(a,b);}
int sub(int a,int b){return a>=b?a-b:a-b+MOD;}
void dsub(int &a,int b){a=sub(a,b);}
int mul(int a,int b){return (LL)a*b%MOD;}

const int N=1.01e5;
int a[N];
int l[N],r[N],c[N];

void work(){
	int n=read();
	F(i,1,n)a[i]=read();
	// cerr<<n<<endl;
	// F(i,1,n)cerr<<"a["<<i<<"]="<<a[i]<<endl;
	int ans=0;
	int ttans=0;
	F(i,1,n){
		// cerr<<i<<endl;
		l[i]=r[i]=a[i];
		c[i]=1;
		R(j,i-1,1){
			dsub(ttans,mul(j,c[j]-1));
			bool did=false;
			if(r[j]>l[j+1]){
				did=true;
				// cerr<<i<<" "<<j<<" "<<l[j+1]<<endl;
				c[j]=(a[j]-1)/l[j+1]+1;
				// cerr<<"c["<<j<<"]->"<<c[j]<<endl;
				r[j]=(a[j]-1)/c[j]+1;
				// assert(r[j]<=l[j+1]);
				// assert(c[j]==1||(a[j]-1)/(c[j]-1)+1>l[j+1]);
				l[j]=a[j]/c[j];
			}
			dadd(ttans,mul(j,c[j]-1));
			if(!did)break;
		}
		dadd(ans,ttans);
	}
	printf("%d\n",ans);
}

int main(){
	int t=read();
	D(_,t)work();
	return 0;
}