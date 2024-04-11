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

const int N=1.1e6;
const int X=5.01e5;
int n;
int cnt[N];

bool pick(int x,int y,int w){
	int len=y*w/2;
	LL seg=0;
	int good=0,bad=0;
	for(int i=0;i*x<=X;i++){
		int l=max(i*x,0);
		int par=i*x+y%x;
		int r=(i+1)*x;
		int c=cnt[r-1]-(l>0?cnt[l-1]:0);
		seg+=(LL)c*i;
		if(l<=par&&par<=r){
			int mp=max(par,y);
			int ml=max(l,y);
			int mr=max(r,y);
			good+=cnt[mr-1]-(mp>0?cnt[mp-1]:0);
			bad+=(mp>0?cnt[mp-1]:0)-(ml>0?cnt[ml-1]:0);
		}
	}
	// cerr<<"pick "<<x<<" "<<y<<" "<<w<<endl;
	// cerr<<"seg="<<seg<<" good="<<good<<" bad="<<bad<<endl;
	if(good+bad<w)return false;
	seg-=y/x*w;
	seg-=max(w-good,0);
	return seg>=len;
}

bool test(int x,int y){
	return pick(x,2*y,1)||pick(x,y,2);
}

int main(){
	n=read();
	F(i,1,n)cnt[read()]++;
	D(i,N)if(i)cnt[i]+=cnt[i-1];
	LL ans=0;
	// test(9,10);
	F(i,2,X){
		if(test(i,2)){
			int l=2,r=X;
			while(l<r){
				int mid=(l+r+1)>>1;
				// cerr<<"mid="<<mid<<endl;
				if(test(i,mid))l=mid;
				else r=mid-1;
			}
			ans=max(ans,(LL)l*i);
		}
	}
	printf("%lld\n",ans);
	return 0;
}