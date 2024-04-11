#include<bits/stdc++.h>
#define N 400005
#define M 8000005
using namespace std;

int n,last=1,cnt=1,trtot,dp[N],ch[N][26],len[N],id[N],fa[N],pos[N],sum[N],q[N],rt[N],ls[M],rs[M];
char s[N]; bool bo[N];
void extend(int k,int x){
	int p=last,np=last=++cnt; len[np]=len[p]+1;
	id[np]=k; bo[np]=1;
	for (; p && !ch[p][x]; p=fa[p]) ch[p][x]=np;
	if (!p){ fa[np]=1; return; }
	int q=ch[p][x];
	if (len[p]+1==len[q]) fa[np]=q; else{
		int nq=++cnt;
		len[nq]=len[p]+1; id[nq]=id[q];
		memcpy(ch[nq],ch[q],sizeof(ch[q]));
		fa[nq]=fa[q]; fa[q]=fa[np]=nq;
		for (; p && ch[p][x]==q; p=fa[p]) ch[p][x]=nq;
	}
}
void build(){
	int i;
	for (i=1; i<=cnt; i++) sum[len[i]]++;
	for (i=1; i<=n; i++) sum[i]+=sum[i-1];
	for (i=cnt; i; i--) q[sum[len[i]]--]=i; 
}
void ins(int &k,int l,int r,int x){
	k=++trtot;
	if (l==r) return; int mid=(l+r)>>1;
	if (x<=mid) ins(ls[k],l,mid,x); else ins(rs[k],mid+1,r,x);
}
int merge(int x,int y){
	if (!x || !y) return x|y;
	int t=++trtot;
	ls[t]=merge(ls[x],ls[y]); rs[t]=merge(rs[x],rs[y]);
	return t;
}
bool ok(int k,int l,int r,int x,int y){
	if (!k) return 0; 
	if (x<=l && r<=y) return 1;
	int mid=(l+r)>>1;
	if (x<=mid) if (ok(ls[k],l,mid,x,y)) return 1;
	if (y>mid) return ok(rs[k],mid+1,r,x,y); else return 0;
}
int main(){
	scanf("%d%s",&n,s+1);
	int i,j,k;
	for (i=1; i<=n; i++) extend(i,s[i]-'a');
	build();
	for (i=cnt; i>1; i--){
		j=q[i]; k=0;
		if (bo[j]){ ins(k,1,n,id[j]); rt[j]=merge(rt[j],k); }
		rt[fa[j]]=merge(rt[fa[j]],rt[j]);
	}
	int ans=1;
	for (i=2; i<=cnt; i++){
		j=q[i];
		if (fa[j]==1){
			dp[j]=1; pos[j]=j; continue;
		}
		if (ok(rt[pos[fa[j]]],1,n,id[j]-len[j]+len[pos[fa[j]]],id[j]-1)){
			dp[j]=dp[fa[j]]+1; pos[j]=j;
		} else{
			dp[j]=dp[fa[j]]; pos[j]=pos[fa[j]];
		}
		ans=max(ans,dp[j]);
	}
	printf("%d\n",ans);
	return 0;
}