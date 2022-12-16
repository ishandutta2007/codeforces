#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=768;
const int M=1.01e7;
const int C=2;

namespace ACAM{

struct Node{
	int ch[C],fa,tfa;
}o[M];

int ncnt=0;
int rt=++ncnt;

char tmp[M];
int insert(){
	int now=rt;
	for(int i=0;tmp[i];i++){
		int &v=o[now].ch[(int)tmp[i]-'a'];
		if(!v)v=++ncnt;
		now=v;
	}
	return now;
}

int q[M];
void build(){
	int *l=q+1,*r=l;
	o[rt].fa=-1;
	o[rt].tfa=-1;
	*r++=rt;
	while(l!=r){
		int x=*l++;
		int f=o[x].fa;
		D(i,C){
			int &v=o[x].ch[i];
			if(v){
				*r++=v;
				o[v].tfa=x;
			}
			(v?o[v].fa:v)=(f!=-1?o[f].ch[i]:rt);
		}
	}
}

};
using namespace ACAM;

int suf[M];

int last[N];
bitset<N> e[N];

int n;
bool ok[N];
bool vis[N];
bool rvis[N];
int cp[N];
int lcp[N];
bool dfs(int x){
	vis[x]=true;
	if(lcp[x])rvis[lcp[x]]=true;
	F(y,1,n)if(e[x][y]&&(!cp[y]||(!vis[cp[y]]&&dfs(cp[y])))){
		cp[y]=x;
		lcp[x]=y;
		return true;
	}
	return false;
}

int main(){
	n=read();
	F(i,1,n){
		scanf("%s",tmp);
		last[i]=insert();
		suf[last[i]]=i;
	}
	build();
	F(i,2,ncnt){
		int x=q[i];
		if(!suf[x])suf[x]=suf[o[x].fa];
	}
	F(i,1,n){
		for(int x=last[i];x!=-1;x=o[x].tfa){
			int id=suf[x!=last[i]?x:o[x].fa];
			if(id){
				// cerr<<i<<" "<<id<<endl;
				e[i][id]=true;
			}
		}
	}
	F(i,1,n)e[i][i]=true;
	F(k,1,n)F(i,1,n)if(e[i][k])e[i]|=e[k];
	F(i,1,n)e[i][i]=false;
	// F(i,1,n)F(j,1,n)if(e[i][j])cerr<<i<<" -> "<<j<<endl;
	F(i,1,n){
		memset(vis,false,sizeof(vis));
		ok[i]=dfs(i);
	}
	memset(vis,false,sizeof(vis));
	memset(rvis,false,sizeof(rvis));
	F(i,1,n)if(!ok[i])dfs(i);
	V ans;
	F(i,1,n)if(vis[i]&&!rvis[i])ans.push_back(i);
	printf("%d\n",(int)ans.size());
	D(i,ans.size())printf("%d ",ans[i]);
	printf("\n");
	return 0;
}