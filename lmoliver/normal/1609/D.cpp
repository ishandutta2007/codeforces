#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=1010;
int cnt[N];
struct UFS{
	int fa[N];
	int sz[N];
	int find(int x){return fa[x]?fa[x]=find(fa[x]):x;}
	bool merge(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y)return false;
		cnt[sz[x]]--;
		cnt[sz[y]]--;
		sz[y]+=sz[x];
		fa[x]=y;
		cnt[sz[y]]++;
		return true;
	}
}ufs;

int main(){
	int n=read(),d=read();
	cnt[1]=n;
	F(i,1,n)ufs.sz[i]=1;
	int ltk=1;
	D(_,d){
		int x=read(),y=read();
		ltk+=!ufs.merge(x,y);
		int t=ltk;
		int ans=0;
		R(i,n,1){
			int c=min(cnt[i],t);
			ans+=c*i;
			t-=c;
		}
		ans-=1;
		printf("%d\n",ans);
	}
	return 0;
}