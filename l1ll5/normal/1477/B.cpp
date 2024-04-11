#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
string s,t;
int l[N],r[N];

int n,q;
int sum[N<<2];
int tag[N<<2];

#define ls x<<1
#define rs x<<1|1

void pushup(int x) {
    sum[x] = sum[ls] + sum[rs];
}
void pushdown(int x,int l,int r) {
    if(tag[x] != -1) {
        tag[ls] = tag[x];
        tag[rs] = tag[x];
        int mid=(l+r)>>1;
        sum[ls] = (mid - l + 1) * tag[x];
        sum[rs] = (r - mid) * tag[x];
        tag[x] = -1;
    }
}

void cover(int x,int l,int r,int L,int R,int v) {
    if(l>=L && r<=R) {
        sum[x] = (r-l+1) * v;
        tag[x] = v;
        return ;
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(L<=mid) cover(ls,l,mid,L,R,v);
    if(R>mid ) cover(rs,mid+1,r,L,R,v);
    pushup(x);
}

int ask(int x,int l,int r,int L,int R) {
    if(l>=L && r<=R) {
        return sum[x];
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1,ret=0;
    if(L<=mid) ret+=ask(ls,l,mid,L,R);
    if(R>mid ) ret+=ask(rs,mid+1,r,L,R);
    pushup(x);
    return ret;
}

void build(int x,int l,int r) {
    tag[x] = -1;
    sum[x] = 0;
    if(l==r) {
        sum[x] = (t[l-1] - '0');
        return ;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(x);
}

int main()
{
    //freopen("3.in","r",stdin);
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>q;
        cin>>s>>t;
        for(int i=1;i<=q;i++) cin>>l[i]>>r[i];

        build(1,1,n);
        bool ok = 1;
        for(int i=q;i>=1;i--) {
            int L=l[i],R=r[i];
            int s1 = ask(1,1,n,L,R);
            int s0 = (R - L + 1) - s1;
        //    cerr<<i<<' '<<s1<<' '<<s0<<endl;
            if(s1==s0) {
                ok=0;
                break ;
            }
            if(s0 > s1) {
                cover(1,1,n,L,R,0);
            } else {
                cover(1,1,n,L,R,1);
            }
        }

        for(int i=1;i<=n;i++) {
            int tmp = ask(1,1,n,i,i);
            //cerr<<i<<' '<<tmp<<endl;
            //cout<<tmp;
            if(tmp != s[i-1]-'0') {
                ok=0;
                break ;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
}