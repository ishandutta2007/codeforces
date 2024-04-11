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
	return x;
}

const int N=100100;
struct P{int z,id;bool tp;};
P v[2*N];
const int T=1.1e6;
V es[T];
int t[N],x[N],y[N];
const int R=555;
int a[R][R]={0};
int ans[N];
void dmax(int &a,int b){a=max(a,b);}
int qwq[2*N];
bool del[N];
int main(){
	int r=read(),n=read();
	F(i,0,n){
		t[i]=i?read():0;
		x[i]=i?read():1;
		y[i]=i?read():1;
		if(t[i]-r>=0)es[t[i]-r].push_back(-i);
		es[t[i]+r].push_back(i);
	}
	list<int> s;
	for(int i=T-1;i>=0;i--){
		for(int x:es[i]){
			if(x>=0)s.push_back(x);
			else del[-x]=true;
		}
		for(auto x=s.begin();x!=s.end();){
			if(del[*x])x=s.erase(x);
			else x++;
		}
		int qs=0;
		for(int x:s)qwq[qs++]=x;
		// D(i,vs){
		// 	P p=v[i];
		// 	if(p.tp){
		// 		dmax(a[x[p.id]][p.z],ans[p.id]+1);
		// 	}
		// 	else{
		// 		dmax(ans[p.id],a[p.z][y[p.id]]);
		// 	}
		// }
#define QAQ1(COND,Z) do{if(COND)dmax(a[x][Z],ans[id]+1);}while(false)
#define QAQ2(COND,Z) do{if(COND)dmax(ans[id],a[Z][y]);}while(false)
#define FOR(STMT) \
		for(auto it=qwq;it!=qwq+qs;++it){\
			int id=*it;\
			int t=::t[id];\
			int x=::x[id];\
			int y=::y[id];\
			int d=i-t;\
			STMT;\
		}
		FOR(if(d<0){QAQ1(y-d<=r,y-d);QAQ1(y+d>=1,y+d);});
		FOR(if(d==0){QAQ2(true,x);QAQ1(true,y);});
		FOR(if(d>0){QAQ2(x+d<=r,x+d);QAQ2(x-d>=1,x-d);});
	}
	printf("%d\n",ans[0]);
	return 0;
}