#include<bits/stdc++.h>
using namespace std;
const int N=7e5+9;

struct TRIE {
	int ch[N*32][2],root[N*32]; int tot;
	long long sz[N*32];
	void ins(int val,int rt,int u=0) {
		if(!root[rt]) root[rt]=++tot;
		u=root[rt], sz[u]++;
		for(int h=30;h>=0;h--) {
			bool p=val&(1<<h);
			if(!ch[u][p]) ch[u][p]=++tot;
			u=ch[u][p]; sz[u]++;
		}
	}
	void del(int val,int rt,int u=0) {
		u=root[rt]; sz[u]--;
		for(int h=30;h>=0;h--) {
			bool p=val&(1<<h);
			if(!ch[u][p]) return;
			u=ch[u][p]; sz[u]--;
		}
	}
	long long rank_small(int val,vector<int>c1,vector<int>c2,long long ans=0) {
		int len1=c1.size();
		for(int i=0;i<len1;i++) {
			for(int h=30;h>=0;h--) {
				bool p=val&(1<<h);
				if(p&&ch[c1[i]][0]) ans-=sz[ch[c1[i]][0]];
				c1[i]=ch[c1[i]][p];
				if(!c1[i]) break;
			}
		}
		int len2=c2.size();
		for(int i=0;i<len2;i++) {
			for(int h=30;h>=0;h--) {
				bool p=val&(1<<h);
				if(p&&ch[c2[i]][0]) ans+=sz[ch[c2[i]][0]];
				c2[i]=ch[c2[i]][p];
				if(!c2[i]) break;
			}
		}
		return ans;
	}
	long long rank_large(int val,vector<int>c1,vector<int>c2,long long ans=0) {
		int len1=c1.size();
		for(int i=0;i<len1;i++) {
			for(int h=30;h>=0;h--) {
				bool p=val&(1<<h);
				if((!p)&&ch[c1[i]][1]) ans-=sz[ch[c1[i]][1]];
				c1[i]=ch[c1[i]][p];
				if(!c1[i]) break;
			}
		}
		int len2=c2.size();
		for(int i=0;i<len2;i++) {
			for(int h=30;h>=0;h--) {
				bool p=val&(1<<h);
				if((!p)&&ch[c2[i]][1]) ans+=sz[ch[c2[i]][1]];
				c2[i]=ch[c2[i]][p];
				if(!c2[i]) break;
			}
		}
		return ans;
	}
}tr;

int n,m,a[N];

#define lb(i) (i&(-i))
void add(int x,int a) {for(;x<=n;x+=lb(x)) tr.ins(a,x);}
void rem(int x,int a) {for(;x<=n;x+=lb(x)) tr.del(a,x);}
long long query_small(int x,int y,int k) {
	if(x>y) return 0; vector<int>c1,c2;
	for(int j=x-1;j>=1;j-=lb(j)) c1.push_back(tr.root[j]);
	for(int j=y;j>=1;j-=lb(j)) c2.push_back(tr.root[j]);
	return tr.rank_small(k,c1,c2);
}
long long query_large(int x,int y,int k) {
	if(x>y) return 0; vector<int>c1,c2;
	for(int j=x-1;j>=1;j-=lb(j)) c1.push_back(tr.root[j]);
	for(int j=y;j>=1;j-=lb(j)) c2.push_back(tr.root[j]);
	return tr.rank_large(k,c1,c2);
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		a[i]=i, add(i,a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++) ans+=query_small(i+1,n,a[i]); 
	for(int i=1,x,y;i<=m;i++) {
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		if(a[x]==a[y]) {printf("%lld\n",ans);continue;}
		if(x+1!=y) {
			ans-=query_large(1,y-1,a[y])-query_large(1,x,a[y]),
			ans-=query_small(1,y-1,a[x])-query_small(1,x,a[x]),
			ans+=query_small(1,y-1,a[y])-query_small(1,x,a[y]),
			ans+=query_large(1,y-1,a[x])-query_large(1,x,a[x]);
		}
		ans+=(a[x]<a[y]? 1 : -1); printf("%lld\n",ans);
		rem(x,a[x]), rem(y,a[y]), add(x,a[y]), add(y,a[x]), swap(a[x],a[y]);
	}
	return 0;
}