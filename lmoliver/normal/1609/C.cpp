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
const int M=1.1e6;
bool np[M];
void init(){
	np[0]=np[1]=true;
	F(i,2,M-1){
		if(!np[i]){
			for(int j=i*2;j<M;j+=i)np[j]=true;
		}
	}
}

void work(){
	int n=read(),e=read();
	F(i,1,n)a[i]=read();
	LL ans=0;
	F(i,1,e){
		V qwq;
		for(int j=i;j<=n;j+=e){
			qwq.push_back(a[j]==1?0:!np[a[j]]?1:2);
		}
		// cerr<<i<<" "<<qwq.size()<<endl;
		D(j,qwq.size()){
			if(qwq[j]==1){
				int l;
				for(l=j-1;l>=0&&qwq[l]==0;l--){}
				int r;
				for(r=j+1;r<(int)qwq.size()&&qwq[r]==0;r++){}
				// cerr<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
				ans+=(LL)(r-j)*(j-l)-1;
			}
		}
	}
	printf("%lld\n",ans);
}

int main(){
	init();
	int t=read();
	D(_,t)work();
	return 0;
}