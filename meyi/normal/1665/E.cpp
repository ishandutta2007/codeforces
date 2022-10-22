#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int lim=31,maxn=1e5+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;

struct segment_tree{
	int l,r;
	vector<int>v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
int a[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	vector<int>().swap(t[p].v);
	if(l==r){
		t[p].v.push_back(a[l]);
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p].v.resize(t[ls(p)].v.size()+t[rs(p)].v.size());
	merge(t[ls(p)].v.begin(),t[ls(p)].v.end(),t[rs(p)].v.begin(),t[rs(p)].v.end(),t[p].v.begin());
	if(t[p].v.size()>lim)t[p].v.erase(t[p].v.begin()+lim,t[p].v.end());
}
vector<int>ans;
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subseg (l<=t[p].l&&t[p].r<=r)
void query(int p,int l,int r){
	if(no_intersection)return;
	if(is_subseg){
		vector<int>tmp(ans.size()+t[p].v.size());
		merge(ans.begin(),ans.end(),t[p].v.begin(),t[p].v.end(),tmp.begin());
		if(tmp.size()>lim)tmp.erase(tmp.begin()+lim,tmp.end());
		ans=tmp;
		return;
	}
	query(ls(p),l,r);
	query(rs(p),l,r);
}
int m,n,t_case;
int main(){
	t_case=qr();
	while(t_case--){
		n=qr();
		for(ri i=1;i<=n;++i)a[i]=qr();
		build(1,1,n);
		m=qr();
		while(m--){
			ri l=qr(),r=qr();
			vector<int>().swap(ans);
			query(1,l,r);
			ri mn=(1<<30)-1;
			for(ri i=0;i<ans.size();++i){
				if(ans[i]>=mn)break;
				for(ri j=i+1;j<ans.size();++j)ckmin(mn,ans[i]|ans[j]);
			}
			qw(mn),putchar(10);
		}
	}
	return 0;
}