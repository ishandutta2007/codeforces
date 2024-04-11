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

const int N=1e6+5;
int n;
char s[N];
struct SAM {
	int ch[N][26],link[N],len[N],nds,pos[N],lst,idx[N];
	void extend(int c,int i) {
		int np=++nds,p=lst; lst=np;
		idx[pos[np]=i]=np; len[np]=len[p]+1;
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
	void test(int u,string s) {
		cout<<u<<' '<<len[u]<<' '<<link[u]<<' ' <<s<<endl;
		fo(i,0,26) if(ch[u][i]) test(ch[u][i],s+(char)('a'+i));
	}
} sam;
const int NN=N*20;
int nds,rt[N],ch[NN][2],siz[NN];
#define lc ch[k][0]
#define rc ch[k][1]
#define left lc,l,mid
#define right rc,mid+1,r
void pushup(int k) {siz[k]=siz[lc]+siz[rc];}
void grow(int &k,int l,int r,int pos) {
	if(!k) k=++nds;
	++siz[k];
	if(l==r) return;
	int mid=l+r>>1;
	if(pos<=mid) grow(left,pos);
	else grow(right,pos);
}
int merge(int a,int b,int l,int r) {
	if(!a||!b) return a|b;
	int k=++nds;
	assert(l!=r); int mid=l+r>>1;
	lc=merge(ch[a][0],ch[b][0],l,mid);
	rc=merge(ch[a][1],ch[b][1],mid+1,r);
	return pushup(k),k;
}
int search(int k,int l,int r,int lim) {
	if(!siz[k]) return -1;
	if(l==r) return l;
	int mid=l+r>>1,res=-1;
	if(siz[lc]&&lim<=mid) res=search(left,lim);
	return ~res?res:search(right,lim);
}
vector<int> G[N];
void addedge(int u,int v) {G[u].push_back(v);}
int bz[N][20];
void dfs(int u) {
	bz[u][0]=sam.link[u];
	fr(i,1,19) bz[u][i]=bz[bz[u][i-1]][i-1];
	if(sam.pos[u]) grow(rt[u],1,n,sam.pos[u]);
	for(auto v:G[u]) dfs(v),rt[u]=merge(rt[u],rt[v],1,n);
}

int dp[N];
int chk(int i,int j) {
	if(j<=1) return 1;
	if(i+j>n) return 0;
	int u=sam.idx[i];
	rf(k,19,0) if(sam.len[bz[u][k]]>=j-1) u=bz[u][k];
	int p=search(rt[u],1,n,i+j);
	if(~p&&dp[p]>=j-1) return 1;
	u=sam.idx[i+1];
	rf(k,19,0) if(sam.len[bz[u][k]]>=j-1) u=bz[u][k];
	p=search(rt[u],1,n,i+j);
	return ~p&&dp[p]>=j-1;
}
int main() {
	scanf("%d%s",&n,s+1);
	rf(i,n,1) sam.extend(s[i]-'a',i);
	fr(i,1,sam.nds) addedge(sam.link[i],i);
	dfs(0);
	for(int i=n,j=0;i>=1;--i) {
		for(++j;!chk(i,j);--j);
		dp[i]=j;
	}
	printf("%d\n",*max_element(dp+1,dp+n+1));
	return 0;
}