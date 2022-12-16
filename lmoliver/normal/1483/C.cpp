#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
int read(){int x;scanf("%d",&x);return x;}

const int N=3.3e5;
int h[N];
int b[N];
int l[N],r[N];
int lc[N],rc[N];

LL solve(int id,bool lr,int rr){
	if(!id)return 0;
	// cerr<<id<<" "<<h[id]<<endl;
	// cerr<<"lc="<<lc[id]<<" rc="<<rc[id]<<endl;
	LL lv=solve(lc[id],lr,true);
	LL rv=solve(rc[id],true,rr);
	LL ans=b[id]+lv+rv;
	if(lr)ans=max(ans,rv);
	if(rr)ans=max(ans,lv);
	return ans;
}

int main(){
	int n=read();
	F(i,1,n)h[i]=read();
	F(i,1,n)b[i]=read();
	h[0]=h[n+1]=INT_MIN;
	int rt=0;
	F(i,1,n){
		l[i]=i-1;
		while(h[l[i]]>h[i])l[i]=l[l[i]];
	}
	R(i,n,1){
		r[i]=i+1;
		while(h[r[i]]>h[i])r[i]=r[r[i]];
	}
	F(i,1,n){
		if(l[i]==0&&r[i]==n+1)rt=i;
		else{
			(h[l[i]]>h[r[i]]?rc[l[i]]:lc[r[i]])=i;
		}
	}
	LL ans=solve(rt,false,false);
	printf("%lld\n",ans);
	return 0;
}