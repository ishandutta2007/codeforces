#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=300300;
map<int,int> mps[N];
int a[N];
int pr[N];
LL cnt[N];
int main(){
	int q=read();
	D(_,q){
		int n=read();
		F(i,1,n)a[i]=read();
		F(i,1,n){
			auto &mp=mps[i-1];
			auto it=mp.find(a[i]);
			if(it==mp.end()){
				pr[i]=0;
			}
			else{
				pr[i]=it->second;
				swap(mps[pr[i]-1],mps[i]);
			}
			mps[i][a[i]]=i;
		}
		// F(i,1,n)cerr<<"pr["<<i<<"]="<<pr[i]<<endl;
		F(i,1,n)cnt[i]=pr[i]?cnt[pr[i]-1]+1:0;
		LL ans=0;
		F(i,1,n)ans+=cnt[i];
		printf("%lld\n",ans);
		F(i,1,n)mps[i].clear();
	}
	return 0;
}