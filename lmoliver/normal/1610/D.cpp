#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int MOD=1e9+7;
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

const int N=2.1e5;
int a[N];
int cnt[N];
int scnt[N];

int main(){
	int n=read();
	F(i,1,n){
		a[i]=read();
		int c=0;
		while(!(a[i]&1)){
			c++;
			a[i]>>=1;
		}
		cnt[c]++;
	}
	int ans=0;
	F(i,0,30){
		F(j,i+1,30)scnt[i]+=cnt[j];
		if(cnt[i]){
			if(i){
				dadd(ans,
					mul(
						sub(ksm(2,cnt[i]-1),1),
						ksm(2,scnt[i])
					)
				);
			}
			else{
				dadd(ans,
					mul(
						sub(ksm(2,cnt[i]),1),
						ksm(2,scnt[i])
					)
				);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}