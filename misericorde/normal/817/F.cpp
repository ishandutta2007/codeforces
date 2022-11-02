#include <cstdio>
#include <algorithm>
#define maxn 400205

int q;
long long l[100005], r[100005]; int t[100005];
long long seq[400055];

struct segmentTree {
    int left[maxn<<2], right[maxn<<2], val[maxn<<2], tag[maxn<<2];
    void update(int x) {val[x]=val[x<<1]+val[x<<1|1];}
    void give_tag(int x, int v) {
        if (v==2) {
            if (tag[x]==-1) tag[x]=2;
            else if (tag[x]==2) tag[x]=-1;
            else tag[x]=tag[x]^1;
            val[x]=(right[x]-left[x]+1)-val[x];
        } else {
            tag[x]=v;
            val[x]=(right[x]-left[x]+1)*v;
        }
    }void pushtag(int x) {
        if (tag[x]!=-1) {
            give_tag(x<<1, tag[x]);
            give_tag(x<<1|1, tag[x]);
            tag[x]=-1;
        }
    }		
    void build(int l, int r, int x) {
        left[x]=l; right[x]=r;
        if (l==r) {
            val[x]=0; tag[x]=-1;
            return;
        } build(l, (l+r)>>1, x<<1);
        build(((l+r)>>1)+1, r, x<<1|1);
        update(x);
    } void modify(int l, int r, int v, int x) {
    //	printf("%d\n", x);
        if (left[x]>r||right[x]<l) return;
        if (l<=left[x]&&right[x]<=r) {
            give_tag(x, v);
            return;
        } pushtag(x);
        modify(l, r, v, x<<1); modify(l, r, v, x<<1|1);
        update(x);
        return;
    }  int query(int x) {
        if (left[x]==right[x]) return left[x];
        pushtag(x);
        if (val[x<<1]<(right[x<<1]-left[x<<1]+1)) return query(x<<1);
        else return query(x<<1|1);
    }
}segTree;

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
    scanf("%d", &q);
    for (int i=1;i<=q;++i) {
        scanf("%d %lld %lld", &t[i], &l[i], &r[i]);
        seq[i*4-3]=l[i]; seq[i*4-2]=r[i]; seq[i*4-1]=r[i]+1; 
        seq[i*4]=std::max((long long)1, l[i]-1); 
    }seq[q*4+1]=1;
    std::sort(seq+1, seq+q*4+2);
    int cnt=std::unique(seq+1, seq+q*4+2)-(seq+1);
//	printf("!");
    segTree.build(1, cnt, 1);
//	for (int i=1;i<=cnt;++i) printf("%d ", seq[i]);
    for (int i=1;i<=q;++i) {
        int L=std::lower_bound(seq+1, seq+cnt+1, l[i])-(seq+1)+1;
        int R=std::lower_bound(seq+1, seq+cnt+1, r[i])-(seq+1)+1;
    //	printf("%d<->%d\n", L, R);
        if (t[i]==1) segTree.modify(L, R, 1, 1);
        if (t[i]==2) segTree.modify(L, R, 0, 1);
        if (t[i]==3) segTree.modify(L, R, 2, 1);
        printf("%lld\n", seq[segTree.query(1)]);
    }
    return 0;
}