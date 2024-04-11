#include<cstdio>
#include<cstring>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXM=2e5+5;
int n;
char s[MAXM];
struct node{
	int fa,len,ch[26];
}dat[MAXM];
int cntp,las;
ll sum[MAXM];
inline void Ins(char c){
	c-='a';
	int p=las;
	int np=las=++cntp;
	dat[np].len=dat[p].len+1;
	while(p&&!dat[p].ch[c]) dat[p].ch[c]=np,p=dat[p].fa;
	if(p){
		int q=dat[p].ch[c];
		if(dat[q].len>dat[p].len+1){
			int nq=++cntp;
			dat[nq]=dat[q];
			dat[nq].len=dat[p].len+1;
			dat[np].fa=dat[q].fa=nq;
			while(p&&dat[p].ch[c]==q) dat[p].ch[c]=nq,p=dat[p].fa;
		}else dat[np].fa=q;
	}else dat[np].fa=1;
	sum[np]++;
	return ;
}
ll ans;
int cnte,h[MAXM],to[MAXM],nx[MAXM];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
void Dfs(int u){
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		Dfs(v);
		sum[u]+=sum[v];
	}
	ans+=sum[u]*sum[u]*(dat[u].len-dat[dat[u].fa].len);
	return ;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		ans=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		cnte=0;
		memset(h,0,sizeof(h));
		memset(dat,0,sizeof(dat));
		memset(sum,0,sizeof(sum));
		cntp=las=1;
		for(int i=1; i<=n; i++)
			Ins(s[i]);
		for(int i=2; i<=cntp; i++)
			adde(dat[i].fa,i);
		Dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}