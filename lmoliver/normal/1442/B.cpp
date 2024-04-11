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

const int N=2.1e5;
int a[N],b[N];
int id[N];
const int MOD=998244353;
int add(int a,int b){return (a+b)%MOD;}
int ans[N];
int nxt[N],pre[N];
int main(){
	int t=read();
	D(_,t){
		int n=read(),k=read();
		F(i,1,n)a[i]=read();
		F(i,1,n)pre[i]=i-1;
		F(i,1,n)nxt[i]=i==n?0:i+1;
		pre[0]=n;
		nxt[0]=1;
		F(i,1,n)id[a[i]]=i;
		F(i,1,k)b[i]=id[read()];
		set<int> s(b+1,b+k+1);
		int ans=1;
		F(i,1,k){
			int cb=b[i];
			int pv=pre[cb];
			int nv=nxt[cb];
			bool ip=pv&&!s.count(pv);
			bool in=nv&&!s.count(nv);
			if(ip&&in)ans=add(ans,ans);
			else if(!ip&&!in){
				ans=0;
				break;
			}
			else if(ip){
				nxt[pre[pv]]=cb;
				pre[cb]=pre[pv];
			}
			else{
				pre[nxt[pv]]=cb;
				nxt[cb]=nxt[nv];
			}
			s.erase(cb);
		}
		printf("%d\n",ans);
	}
	return 0;
}