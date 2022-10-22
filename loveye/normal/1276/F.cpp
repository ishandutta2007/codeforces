#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5;
int n; ll ans;
char s[N];
struct SA {
	int sig='z',c[N],x[N],y[N],sa[N],ht[N],rk[N],st[20][N];
	void base_sort() {
		fr(i,1,sig) c[i]=0;
		fr(i,1,n) ++c[x[i]];
		fr(i,1,sig) c[i]+=c[i-1];
		rf(i,n,1) sa[c[x[y[i]]]--]=y[i];
	}
	void getSA() {
		fr(i,1,n) x[i]=s[i],y[i]=i;
		base_sort();
		for(int k=1,cur;k<=n;k<<=1) {
			cur=0;
			fr(i,n-k+1,n) y[++cur]=i;
			fr(i,1,n) if(sa[i]>k) y[++cur]=sa[i]-k;
			base_sort(); swap(x,y);
			x[sa[1]]=cur=1;
			fr(i,2,n) if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]) x[sa[i]]=cur;
			else x[sa[i]]=++cur;
			if(cur==n) break;
			sig=cur;
		}
	}
	void getht() {
		fr(i,1,n) rk[sa[i]]=i;
		int k=0;
		fr(i,1,n) {
			if(rk[i]==1) continue;
			int j=sa[rk[i]-1];
			if(k) --k;
			while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) ++k;
			ht[rk[i]]=k;
		}
	}
	int getlcp(int i,int j) {
		if(i>n||j>n) return 0;
		if(i==j) return n-i+1;
		i=rk[i],j=rk[j];
		if(i>j) swap(i,j); ++i;
		int k=__lg(j-i+1);
		return min(st[k][i],st[k][j-(1<<k)+1]);
	}
	void build() {
		getSA(); getht();
		fr(i,1,n) st[0][i]=ht[i];
		fr(k,1,19) fr(i,1,n-(1<<k)+1)
			st[k][i]=min(st[k-1][i],st[k-1][i+(1<<k-1)]);
	}
} sa;
struct SAM {
	int ch[N][26],link[N],len[N],nds,pos[N];
	void extend(int c,int i) {
		static int lst=0;
		int np=++nds,p=lst; lst=np;
		pos[np]=i; len[np]=len[p]+1;
		for(;p&&!ch[p][c];p=link[p]) ch[p][c]=np;
		if(!p&&!ch[p][c]) return link[np]=0,ch[p][c]=np,void();
		int q=ch[p][c];
		if(len[q]==len[p]+1) return link[np]=q,void();
		int nq=++nds; memcpy(ch[nq],ch[q],sizeof ch[0]);
		len[nq]=len[p]+1;
		link[nq]=link[q];
		link[q]=link[np]=nq;
		for(;ch[p][c]==q;p=link[p]) ch[p][c]=nq;
	}
} sam;

const int NN=N*19;
int nds,rt[N],ch[NN][2],L[NN],R[NN]; ll sum[NN];
void pushup(int k) {
	if(!ch[k][0]||!ch[k][1]) {
		int son=ch[k][0]|ch[k][1];
		sum[k]=sum[son]; L[k]=L[son]; R[k]=R[son];
	} else {
		L[k]=L[ch[k][0]]; R[k]=R[ch[k][1]];
		sum[k]=sum[ch[k][0]]+sum[ch[k][1]]-sa.getlcp(sa.sa[R[ch[k][0]]],sa.sa[L[ch[k][1]]]);
	}
}
void grow(int &k,int l,int r,int pos) {
	k=++nds;
	if(l==r) {
		sum[k]=n-sa.sa[pos]+1;
		L[k]=R[k]=pos;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) grow(ch[k][0],l,mid,pos);
	else grow(ch[k][1],mid+1,r,pos);
	pushup(k);
}
void merge(int &a,int &b,int l,int r) {
	if(!a||!b) return a|=b,void();
	assert(l!=r);
	int mid=l+r>>1;
	merge(ch[a][0],ch[b][0],l,mid);
	merge(ch[a][1],ch[b][1],mid+1,r);
	pushup(a);
}
vector<int> G[N];
void addedge(int u,int v) {G[u].push_back(v);}
int tag[N];
void dfs(int u) {
	if(sam.pos[u]==n) tag[u]=-1;
	else tag[u]=1;
	if(sam.pos[u]&&sam.pos[u]<=n-2)
		grow(rt[u],1,n,sa.rk[sam.pos[u]+2]);
	if(!u&&n>1) grow(rt[u],1,n,sa.rk[2]);
	for(auto v:G[u]) dfs(v),merge(rt[u],rt[v],1,n),tag[u]+=tag[v];
	if(tag[u]>=0) {
		if(u) ans+=(sam.len[u]-sam.len[sam.link[u]])*(1+sum[rt[u]]);
		else ans+=1+sum[rt[u]];
	}
}
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	sa.build();
	fr(i,1,n) ans+=n-i+1-sa.ht[i];
	fr(i,1,n) sam.extend(s[i]-'a',i);
	fr(i,1,sam.nds) addedge(sam.link[i],i);
	dfs(0);
	printf("%lld\n",ans+1);
	return 0;
}