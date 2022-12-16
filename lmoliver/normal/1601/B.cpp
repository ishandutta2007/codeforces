#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=3.01e5;
typedef pair<int,int> P;

struct BIT{
	BIT(){memset(a,0x3f,sizeof(a));}
	P a[N];
	P query(int x){
		P p{(int)1e9,-1};
		for(;x;x&=x-1)p=min(p,a[x]);
		return p;
	}
	void set(int x,P p){
		for(;x<N;x+=x&-x)a[x]=min(a[x],p);
	}
}tr;


int a[N],b[N];
P dp[N];

int main(){
	int n=read();
	F(i,1,n)a[i]=read();
	F(i,1,n)b[i]=read();
	dp[0]={0,-1};
	tr.set(N-5-0,{0,0});
	F(i,1,n){
		int nxt=i+b[i];
		P p=tr.query(N-5-(nxt-a[nxt]));
		dp[i]={p.first+1,p.second};
		tr.set(N-5-i,{dp[i].first,i});
		// cerr<<"dp["<<i<<"]={"<<dp[i].first<<","<<dp[i].second<<"}"<<endl;
	}
	if(dp[n].first>5e8){
		puts("-1");
	}
	else{
		printf("%d\n",dp[n].first);
		for(int x=n;dp[x].second!=-1;x=dp[x].second){
			printf("%d ",dp[x].second);
		}
		printf("\n");
	}
	return 0;
}