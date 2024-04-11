#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int b[maxn<<1],bl,cnt,id[maxn],l[maxn],n,op[maxn],r[maxn];
struct dsu{
    int fa[maxn],siz[maxn];
    int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
    inline void merge(int x,int y){
        x=find(x),y=find(y);
        if(x!=y){
            if(siz[x]>siz[y])swap(x,y);
            fa[x]=y,siz[y]+=siz[x];
            ckmin(l[y],l[x]),ckmax(r[y],r[x]);
        }
    }
}d;
struct segment_tree{
	int l,r;
	vector<int>v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r)return;
    ri mid=l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
}
void merge(int p,int k,int v){
    if(t[p].l>k||k>t[p].r)return;
    if(t[p].v.size()){
        for(ri i:t[p].v)d.merge(i,v);
        t[p].v={v};
    }
    if(t[p].l==t[p].r)return;
    merge(ls(p),k,v);
    merge(rs(p),k,v);
}
void insert(int p,int l,int r,int v){
	if(t[p].l>r||l>t[p].r)return;
	if(l<=t[p].l&&t[p].r<=r){
		t[p].v.push_back(v);
		return;
	}
	insert(ls(p),l,r,v);
	insert(rs(p),l,r,v);
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d%d%d",op+i,l+i,r+i);
		if(op[i]&1)b[++bl]=l[i],b[++bl]=r[i];
	}
	sort(b+1,b+bl+1);
	bl=unique(b+1,b+bl+1)-b-1;
	build(1,1,bl);
	for(ri i=1;i<=n;++i){
		if(op[i]&1){
			d.fa[i]=i,d.siz[i]=1;
			id[++cnt]=i;
			l[i]=lower_bound(b+1,b+bl+1,l[i])-b;
			r[i]=lower_bound(b+1,b+bl+1,r[i])-b;
			merge(1,l[i],i);
			merge(1,r[i],i);
			if(l[i]+1<r[i])insert(1,l[i]+1,r[i]-1,i);
		}
		else{
			ri x=d.find(id[l[i]]),y=d.find(id[r[i]]);
			puts(x==y||(l[y]<l[x]&&l[x]<r[y])||(l[y]<r[x]&&r[x]<r[y])?"YES":"NO");
		}
	}
	return 0;
}