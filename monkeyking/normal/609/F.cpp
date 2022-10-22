#include <bits/stdc++.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int gmod=2;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
int n,m;
ll a[500005],r[500005];
ll b[500005],v[500005];

namespace FastIO
{
    const int INPUT_SIZE=10000000;
    char buf[INPUT_SIZE+5];
    int cursor=0;
    inline void init()
    {
        fread(buf,1,INPUT_SIZE,stdin);
    }
    inline char getchar()
    {
        return buf[cursor++];
    }
    inline int getnum()
    {
        static int res;
        static char c;
        res=0;
        c=0;
        while(!isdigit(c)) c=getchar();
        while(isdigit(c))
        {
            res=(res<<3)+(res<<1)+c-'0';
            c=getchar();
        }
        return res;
    }
}
using FastIO::getnum;

namespace PUTLL
{
    int buf[1005];
    inline void putll(ll x)
    {
        int len=0;
        if(x==0)
        {
            buf[len++]=0;
        }
        else
        {
            while(x)
            {
                buf[len++]=x%10;
                x/=10;
            }
            reverse(buf,buf+len);
        }
        for(int i=0;i<len;i++)
        {
            putchar('0'+buf[i]);
        }
    }
};
using PUTLL::putll;

vector <ll> lsh;
int data[500005*4];//id
int nn;
int cnt[500005];
multiset <pair<ll,ll> > foods;

void add(int x,int l,int r,int ql,int qr,int id)
{
    if(qr<=l || ql>=r) return;
    if(l>=ql && r<=qr)
    {
        if(a[data[x]]>a[id])
        {
            data[x]=id;
        }
        return;
    }
    add(x*2,l,l+r>>1,ql,qr,id);
    add(x*2+1,l+r>>1,r,ql,qr,id);
}

inline int query(int x,int l,int r,int pos)
{
    if(pos>=r || pos<l) return n;
    if(l==pos && r==l+1) return data[x];
    int res=data[x];
    int ra=query(x*2,l,l+r>>1,pos);
    int rb=query(x*2+1,l+r>>1,r,pos);
    if(a[ra]<a[res]) res=ra;
    if(a[rb]<a[res]) res=rb;
    return res;
}

inline void add(int i)
{
    int l=lower_bound(all(lsh),a[i])-lsh.begin();
    int r=upper_bound(all(lsh),::r[i])-lsh.begin();
    add(1,0,nn,l,r,i);

}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("b.in","r",stdin);
    // freopen("b.out","w",stdout);
    FastIO::init();
    n=getnum();
    m=getnum();
    for(int i=0;i<n;i++)
    {
        a[i]=getnum();
        r[i]=a[i]+getnum();
    }
    a[n]=llinf;
    for(int i=0;i<m;i++)
    {
        b[i]=getnum();
        v[i]=getnum();
        lsh.push_back(b[i]);
    }
    sort(all(lsh));
    lsh.erase(unique(all(lsh)),lsh.end());
    nn=1;
    while(nn<=m) nn<<=1;
    for(int i=1;i<=nn*2;i++)
    {
        data[i]=n;
    }
    for(int i=0;i<n;i++)
    {
        add(i);
    }
    for(int i=0;i<m;i++)
    {
        int pos=lower_bound(all(lsh),b[i])-lsh.begin();
        int id=query(1,0,nn,pos);
        foods.insert(mp(b[i],v[i]));
        if(id==n) continue;
        while(!foods.empty())
        {
            auto it=foods.lower_bound(mp(a[id],-1LL));
            if(it==foods.end()) break;
            if(it->first>r[id]) break;
            ll B=it->first;
            ll V=it->second;
            foods.erase(it);
            r[id]+=V;
            cnt[id]++;
        }
        add(id);
    }
    for(int i=0;i<n;i++)
    {
        putll(cnt[i]);
        putchar(' ');
        putll(r[i]-a[i]);
        puts("");  
    }
    return 0;
}