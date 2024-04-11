#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
//#define LOCAL
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL
/// seems like I successfully fix my segtree template
/// The last one has so many issues
int n;
template<class T> struct segtreemin{
    static const int Mx=8e5+10;
    /// choose the size properly
    T ma;
    T sg[Mx];
    segtreemin(T _ma,T fi){
        ma=_ma;
        for(int i=0;i<Mx;i++)
            sg[i]=fi;
    }
    void build(T a[],int v,int l,int r){
        if(l==r){
            return (void)(sg[v]=a[l]);
        }
        int mid=l+r>>1;
        build(a,v*2,l,mid);
        build(a,v*2+1,mid+1,r);
        return (void)(sg[v]=min(sg[v*2],sg[v*2+1]));
    }
    T getMin(int v,int x,int y,int l, int r){
        if(l > r)return ma;
        if(l==x && r==y){
            return sg[v];
        }
        int mid=x+y>>1;
        return min(getMin(v*2,x,mid,l,min(r,mid)),getMin(v*2+1,mid+1,y,max(l,mid+1),r));
    }
    void update(int v,int l,int r,int pos,T val){
        if(l==r){
            return (void)(sg[v]=val);
        }
        int mid=l+r>>1;
        (pos<=mid)?update(v*2,l,mid,pos,val):update(v*2+1,mid+1,r,pos,val);
        return (void)(sg[v]=min(sg[v*2],sg[v*2+1]));
    }
    T getMin(int x,int y){
        return getMin(1,1,n,x,y);
    }
    void update(int pos, T val){
        update(1,1,n,pos,val);
    }
};
int k;
char s[maxn];
long long dp[maxn];
long long const inf = 1e17;
int nxt[maxn],lst[maxn];
vector<pair<int,int>> touse[maxn];
void upd(long long &x,long long y){
    if(x > y) x = y;
}

int main(){
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<=n;i++)
        dp[i] = inf;
    for(int i=1;i<=n;i++){
        if(s[i] == '1'){
            touse[min(n,i+k)].emplace_back(max(1,i-k),i);
        }
        else
            touse[i].emplace_back(i,i);
    }
    segtreemin<long long> seg(inf,inf);
   // eprintf("%lld\n",seg.getMin(1,1,n,2,4));
    for(int i=1;i<=n;i++){
        eprintf("alive %d\n",i);
        upd(dp[i],dp[i-1] + i);
        for(auto j:touse[i]){
            eprintf("%d %d\n",j.first, j.second);
            if(j.first == 1)
                upd(dp[i], j.second);
            else upd(dp[i], j.second + seg.getMin(j.first - 1,i - 1));
        }
        eprintf("dp[%d] = %lld\n ",i,dp[i]);
        seg.update(1,1,n,i,dp[i]);
    }
    printf("%lld\n",dp[n]);
}
/*
    Good Luck
        -Lucina
*/