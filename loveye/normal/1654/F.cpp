#include<cstdio>
#include<numeric>
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

const int N=20,M=1<<18|5,MOD=1000100009,S=(5e6+M)*2,base=114519;
int n,pw[M];
int nds;
char s[M];
int a[M];
int ans,rt,ch[S][2],hsh[S];
void pushup(int k,int len) {hsh[k]=(1ll*hsh[ch[k][0]]*pw[len]+hsh[ch[k][1]])%MOD;}
void build(int &k,int l,int r,int d) {
	k=++nds;
	if(l==r) {
		hsh[k]=s[l]-'a';
		return;
	}
	int mid=l+r>>1;
	build(ch[k][0],l,mid,d-1);
	build(ch[k][1],mid+1,r,d-1);
	pushup(k,r-mid);
}
int tag;
void dfs(int &k,int l,int r,int d) {
	if(l==r||(tag&((1<<d+1)-1))==0) return;
	int fr=k; k=++nds; ch[k][0]=ch[fr][0]; ch[k][1]=ch[fr][1];
	if(tag>>d&1) swap(ch[k][0],ch[k][1]);
	int mid=l+r>>1;
	dfs(ch[k][0],l,mid,d-1);
	dfs(ch[k][1],mid+1,r,d-1);
	pushup(k,r-mid);
}
int cmp(int a,int b,int l,int r) {
	if(l==r) return hsh[a]<hsh[b];
	int mid=l+r>>1;
	return hsh[ch[a][0]]^hsh[ch[b][0]]?cmp(ch[a][0],ch[b][0],l,mid):
		cmp(ch[a][1],ch[b][1],mid+1,r);
}
void output(int k,int l,int r) {
	if(l==r) return putchar(hsh[k]+'a'),void();
	int mid=l+r>>1;
	output(ch[k][0],l,mid);
	output(ch[k][1],mid+1,r);
}
int main() {
	cin>>n>>s;
	*pw=1; fo(i,1,1<<n) pw[i]=1ll*pw[i-1]*base%MOD;
	fo(i,0,1<<n) fo(j,0,n) if(i>>j&1) a[i]|=1<<n-1-j;
	build(rt,0,(1<<n)-1,n-1);
	ans=rt;
	fo(i,1,1<<n) {
		tag=a[i]^a[i-1];
		dfs(rt,0,(1<<n)-1,n-1);
		if(cmp(rt,ans,0,(1<<n)-1)) ans=rt;
	}
	output(ans,0,(1<<n)-1);
	return 0;
}