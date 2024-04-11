//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct edge{int to,w,c,nxt;}e[5000005];int et=1,head[5005],a[5005],b[5005],zkak,tn[5005];
int n,m,s,t,ls[5005],fl[5005],q[50005],hd,tl,mf,mc,d[5005],id[5005];char v[5005];
struct out{int id,vl,tg;}r[500005];int rt,hav[5005],vah[5005],hat=0;map<int,int>mp;char ic[5005][5005];
inline void ADDE(int x,int y,int w,int c) {e[++et]=(edge){y,w,c,head[x]},head[x]=et;}
inline void adde(int x,int y,int w,int c) {ADDE(x,y,w,c),ADDE(y,x,0,-c);}
inline char spfa(int s,int t)
{
	memset(d,0x3f,sizeof(d)),memset(v,0,sizeof(v)),q[hd=tl=1]=s,d[s]=0,fl[s]=1e9,ls[t]=0;
	for(int x=s;hd<=tl;v[x=q[++hd]]=0) for(int i=head[x],y=e[i].to;i;y=e[i=e[i].nxt].to)
		if(e[i].w&&d[y]>d[x]+e[i].c) {d[y]=d[x]+e[i].c,ls[y]=i,fl[y]=min(fl[x],e[i].w);if(!v[y]) v[q[++tl]=y]=1;}
	return !!ls[t];
}
inline void upd(int s,int t)
{
	mf+=fl[t],mc+=fl[t]*d[t];int x=t;
	for(;x^s;x=e[ls[x]^1].to) e[ls[x]].w-=fl[t],e[ls[x]^1].w+=fl[t];
}
inline void mcmf(int s,int t) {mf=mc=0;while(spfa(s,t)) upd(s,t);}
inline int cnt(int x) {int r=0;for(;x;x-=x&(-x),r++);return r;}
inline int fnd(int wh)
{
	if(vah[mp[a[wh]]]) return vah[mp[a[wh]]];
	if(hat<m) return ++hat;
	for(int i=1;i<=m;i++) if(!ic[wh][hav[i]]) return i;
	return -1;
}
inline void pt(int wh,int val)
{
	assert(wh>=0);
	if(hav[wh]!=val) r[++rt]=(out){wh,tn[val],1};
	vah[hav[wh]]=0,hav[wh]=val,vah[val]=wh,r[++rt]=(out){wh,0,0};
}
int main()
{
	read(n),read(m),s=n+n+1,t=s+1;for(int i=1;i<=n;i++) read(a[i]),b[i]=cnt(a[i]);
	for(int i=1;i<=n;i++) {adde(i,i+n,1,0),adde(i+n,t,1,0);if(i^n) adde(i,i+1,m-1,0);}
	for(int i=1;i<=n;mp[a[i]]=i,i++) {adde(s,i,1,b[i]);if(mp[a[i]]) id[i]=et+1,adde(i-1,mp[a[i]]+n,1,-b[i]);}
	mp.clear(),zkak=0;for(int i=1;i<=n;i++) if(!mp[a[i]]) mp[a[i]]=++zkak,tn[zkak]=a[i];
	mcmf(s,t);for(int i=1;i<=n;i++) if(id[i]&&!e[id[i]].w) for(int j=e[id[i]].to-n,x=mp[a[i]];j<=i;j++) ic[j][x]=1;
	for(int i=1,tp;i<=n;pt(tp,mp[a[i]]),i++) tp=fnd(i);
	printf("%d %d\n",rt,mc);for(int i=1;i<=rt;i++)
		if(r[i].tg) printf("%c=%d\n",r[i].id+'a'-1,r[i].vl);
		else printf("print(%c)\n",r[i].id+'a'-1);
	return 0;
}