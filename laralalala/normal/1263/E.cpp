#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

template <typename T>
struct ST{
    vector< T > st,lazy;
    int sz;
    T neutroL;

    ST (int n,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        pii res=pii(max(v1.f,v2.f),min(v1.s,v2.s));
        return res;
    }

    void up(int p,int l,int r,T v)
    {
        st[p]=pii(st[p].f+v.f,st[p].s+v.f);
        lazy[p]=pii(lazy[p].f+v.f,0);
    }

    void push(int p,int l,int r)
    {
        if(l==r)
        {
            lazy[p]=neutroL;
            return ;
        }
        if(lazy[p]==neutroL)
            return ;
        ///(basic) up to code
        T v=lazy[p];
        up((p<<1),l,(l+r)>>1,v);
        up((p<<1)+1,((l+r)>>1)+1,r,v);
        lazy[p]=neutroL;
    }

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void build(T *arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,T *arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void update(int L,int R,T v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,T v)
    {
        push(p,l,r);
        if(L<=l && r<=R)
        {
            up(p,l,r,v);
            return ;
        }

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R,v);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        push(p,l,r);
        if(L<=l && r<=R)
            return st[p];

        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R);
        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

int a[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pii> ini(n+2,pii(0,0));
    ST<pii> st(n+2,pii(0,0));
    st.build(ini);
    int p=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        if(c=='L')
            p=max(0,p-1);
        else if(c=='R')
            p++;
        else
        {
            int v=0;
            if(c==')')
                v=-1;
            else if(c=='(')
                v=1;
            if(a[p])
            {
                st.update(p,n+1,pii(-a[p],0));
//                cout << i << ' ' << -a[p] << '\n';
                sum-=a[p];
                a[p]=0;
            }
            if(v)
            {
                a[p]=v;
                st.update(p,n+1,pii(a[p],0));
                sum+=a[p];
//                cout << i << ' ' << a[p] << '\n';
            }
        }

//        db(sum)
        if(sum)
            cout << -1 << ' ';
        else
        {
            pii x=st.query(0,n+1);
            if(x.s)
                cout << -1 << ' ';
            else
                cout << x.f << ' ';
        }
    }
    cout << '\n';

    return 0;
}