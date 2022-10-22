//fuckccf
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,B=330;
int n,q;
string s[MAXN];
int pos[MAXN];
int cntp,ch[MAXN][26],kmp[MAXN];
queue<int> que;
int cnte,h[MAXN],to[MAXN],nx[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
struct node{
	int l,r,id;
};
vector<node> vec[MAXN],lar[MAXN];
int clk,dfn[MAXN],rev[MAXN],siz[MAXN];
int sum[MAXN],tag[B];
void Dfs(int u){
	dfn[u]=++clk;
	rev[clk]=u;
	siz[u]=1;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		Dfs(v);
		siz[u]+=siz[v];
	}
	return ;
}
int Query(int x){
	return sum[x]+tag[x/B];
}
void Add(int l,int r){
	int x=l/B,y=r/B;
	if(x==y){
		for(int i=l; i<=r; i++)
			sum[i]++;
	}else{
		for(int i=x+1; i<y; i++)
			tag[i]++;
		for(int i=l; i/B==x; i++)
			sum[i]++;
		for(int i=r; i/B==y; i--)
			sum[i]++;
	}
	return ;
}
ll ans[MAXN];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++){
		cin>>s[i];
		int u=0;
		for(int j=0; j<s[i].size(); j++){
			int &p=ch[u][s[i][j]-'a'];
			if(!p) p=++cntp;
			u=p;
		}
		pos[i]=u;
	}
	for(int i=0; i<26; i++)
		if(ch[0][i]) que.push(ch[0][i]);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=0; i<26; i++)
			if(ch[u][i]) que.push(ch[u][i]),kmp[ch[u][i]]=ch[kmp[u]][i];
			else ch[u][i]=ch[kmp[u]][i];
	}
	for(int i=1; i<=cntp; i++)
		adde(kmp[i],i);
	Dfs(0);
	for(int i=1; i<=q; i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(s[k].size()>B) lar[k].push_back(node{l,r,i});
		else{
			vec[l-1].push_back(node{k,-1,-i});
			vec[r].push_back(node{k,-1,i});
		}
	}
	for(int k=1; k<=n; k++)
		if(s[k].size()>B){
			int u=0;
			for(int i=0; i<s[k].size(); i++){
				u=ch[u][s[k][i]-'a'];
				sum[u]++;
			}
			for(int i=clk; i>1; i--){
				u=rev[i];
				sum[kmp[u]]+=sum[u];
			}
			static ll pre[MAXN];
			for(int i=1; i<=n; i++)
				pre[i]=pre[i-1]+sum[pos[i]];
			for(node i:lar[k])
				ans[i.id]=pre[i.r]-pre[i.l-1];
			memset(sum,0,sizeof(sum));
		}
	for(int i=1; i<=n; i++){
		Add(dfn[pos[i]],dfn[pos[i]]+siz[pos[i]]-1);
		for(node j:vec[i]){
			ll cnt=0;
			for(int k=0,u=0; k<s[j.l].size(); k++){
				u=ch[u][s[j.l][k]-'a'];
				cnt+=Query(dfn[u]);
			}
			if(j.id>0) ans[j.id]+=cnt;
			else ans[-j.id]-=cnt;
		}
	}
	for(int i=1; i<=q; i++)
		printf("%lld\n",ans[i]);
	return 0;
}