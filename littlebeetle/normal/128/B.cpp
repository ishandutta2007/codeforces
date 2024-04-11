#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
const int N=1000020;
typedef long long ll;
int n,g,i,j,k,ok;
long long p;
char s[N];
int ch[N][26];
struct SAM{
	int len[N],fa[N],cnt=1,lst=1;
	int h[N],t[N],v[N];
	ll sz[N],sum[N];
	void insert(int c){
		int p=lst;
		int np=lst=++cnt;
		len[np]=len[p]+1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p)
			fa[np]=1;
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1)
				fa[np]=q;
			else{
				int nq=++cnt;
				memcpy(ch[nq],ch[q],sizeof(ch[nq]));
				fa[nq]=fa[q];
				len[nq]=len[p]+1;
				fa[np]=fa[q]=nq;
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
			}
		}
		sz[np]=1;
	}
	void add(int a,int b){
		t[++k]=h[a];h[a]=k;v[k]=b;
	}
	void build(){
		for(i=2;i<=cnt;i++)
			add(fa[i],i);
	}
	void dfs(int i){
		for(int j=h[i];j;j=t[j]){
			dfs(v[j]);
			sz[i]+=sz[v[j]];
		}	
		if(g==0)
			sz[i]=1;
	}
	void DFS(int i){
		sum[i]=sz[i];
		for(int j=0;j<26;j++)
			if(ch[i][j]){
				if(sum[ch[i][j]]==0)
				DFS(ch[i][j]);
				sum[i]+=sum[ch[i][j]];
			}
	}
	void out(int i,int p){
		if(sz[i]>=p){
			ok=1;
			return;
		}
		p-=sz[i];
		for(int j=0;j<26;j++){
			if(sum[ch[i][j]]>=p){
				printf("%c",j+97);
				out(ch[i][j],p);
				return;
			}
			p-=sum[ch[i][j]];
		}
	}
}T;
int main(){
	scanf("%s%lld",s+1,&p);
	g=1;
	for(i=1;s[i];i++)
		T.insert(s[i]-97);
	T.build();
	T.dfs(1);
	T.sz[1]=1;
	T.DFS(1);
	T.out(1,p+1);
	if(!ok)
		printf("No such line.");	
	return 0;
}