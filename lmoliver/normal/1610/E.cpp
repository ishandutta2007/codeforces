#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=2.1e5;

int a[N];

void work(){
	map<int,int> cnt;
	int n=read();
	F(i,1,n)a[i]=read();
	F(i,1,n)cnt[a[i]]++;
	int ans=0;
	F(i,1,n){
		if(a[i]==a[i+1])continue;
		int tans=cnt[a[i]];
		for(int x=a[i]+1;;){
			auto it=lower_bound(a+1,a+n+1,x);
			if(it==a+n+1)break;
			else{
				tans++;
				x=2**it-a[i];
			}
		}
		// cerr<<i<<" "<<tans<<endl;
		ans=max(ans,tans);
	}
	printf("%d\n",n-ans);
}

int main(){
	int t=read();
	D(_,t)work();
	return 0;
}