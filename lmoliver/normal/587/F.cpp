#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=1.1e5;
const int C=26;

struct Node{
	int ch[C],fa,tfa;
}o[N];
int ncnt=0;
int rt=++ncnt;
char tmp[N];

struct Res{int last,len;};
Res insert(){
	int now=rt;
	int len=0;
	for(;tmp[len];len++){
		int &c=o[now].ch[tmp[len]-'a'];
		if(!c)c=++ncnt;
		now=c;
	}
	return (Res){now,len};
}

int q[N];
void build(){
	int *l=q+1,*r=l;
	o[rt].tfa=o[rt].fa=-1;
	*r++=rt;
	while(l!=r){
		int x=*l++;
		int f=o[x].fa;
		D(i,C){
			int &c=o[x].ch[i];
			if(c){
				o[c].tfa=x;
				*r++=c;
			}
			(c?o[c].fa:c)=(f==-1?rt:o[f].ch[i]);
		}
	}
}

Res str[N];
vector<LL> pre[N];

LL ans[N];
struct Query{
	int k,w,id;
};
vector<Query> qaq[N];

struct BIT{
	int a[N];
	void add(int x,int v){
		for(;x<N;x+=x&-x)a[x]+=v;
	}
	int query(int x)const{
		int ans=0;
		for(;x;x&=x-1)ans+=a[x];
		return ans;
	}
}tr;

int main(){
	int n=read(),qc=read();
	F(i,1,n){
		scanf("%s",tmp);
		str[i]=insert();
	}
	build();
	int b=sqrt(n)*2;
	F(i,1,n){
		if(str[i].len>b){
			pre[i].resize(n+1);
			static int cnt[N];
			F(i,1,ncnt)cnt[i]=0;
			for(int x=str[i].last;x!=-1;x=o[x].tfa){
				cnt[x]++;
			}
			R(i,ncnt,2)cnt[o[q[i]].fa]+=cnt[q[i]];
			F(j,1,n)pre[i][j]=pre[i][j-1]+cnt[str[j].last];
		}
	}
	D(i,qc){
		int l=read(),r=read(),k=read();
		if(str[k].len>b){
			ans[i]=pre[k][r]-pre[k][l-1];
		}
		else{
			qaq[l-1].push_back((Query){k,-1,i});
			qaq[r].push_back((Query){k,1,i});
		}
	}
	static int sz[N];
	R(i,ncnt,2)sz[o[q[i]].fa]+=++sz[q[i]];
	static int dfn[N],dfe[N];
	F(i,1,ncnt){
		int x=q[i];
		dfn[x]=x==rt?1:dfe[o[x].fa]+1;
		if(x!=rt)dfe[o[x].fa]+=sz[x];
		dfe[x]=dfn[x];
	}
	// F(i,1,ncnt)cerr<<q[i]<<" "<<dfn[q[i]]<<" "<<dfe[q[i]]<<endl;
	F(i,1,n){
		tr.add(dfn[str[i].last],1);
		tr.add(dfe[str[i].last]+1,-1);
		D(j,qaq[i].size()){
			Query q=qaq[i][j];
			for(int x=str[q.k].last;x!=-1;x=o[x].tfa){
				ans[q.id]+=q.w*tr.query(dfn[x]);
			}
		}
	}
	D(i,qc)printf("%lld\n",ans[i]);
	return 0;
}