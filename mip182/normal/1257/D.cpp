#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
 
 
using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
 
ll t[4*MAXN];
ll t1[4*MAXN];
vector <ll> c;
vector <ll> a;
void built(int v,int vl, int vr)
{
    if (vl==vr) {
        t[v] = c[vl];
        return;
    }
    else
    {
        int mid=vl+(vr-vl)/2;
        built ((v<<1)+1,vl,mid);
        built ((v<<1)+2,mid+1,vr);
        t[v]=max(t[(v<<1)+1],t[(v<<1)+2]);
    }
}
 
int sum(int v, int vl, int vr, int l, int r)
{
    if (vr<l||vl>r)
        return -INF-100;
    else{
        if (vl>=l&&vr<=r)
            return t[v];
        int mid=vl+(vr-vl)/2;
        return max(sum((v<<1)+1,vl,mid,l,r),sum((v<<1)+2,mid+1,vr,l,r));
    }
 
}
void built1(int v,int vl, int vr)
{
    if (vl==vr) {
        t1[v] = a[vl];
        return;
    }
    else
    {
        int mid=vl+(vr-vl)/2;
        built1 ((v<<1)+1,vl,mid);
        built1 ((v<<1)+2,mid+1,vr);
        t1[v]=max(t1[(v<<1)+1],t1[(v<<1)+2]);
    }
}
 
int sum1(int v, int vl, int vr, int l, int r)
{
    if (vr<l||vl>r)
        return -INF-100;
    else{
        if (vl>=l&&vr<=r)
            return t1[v];
        int mid=vl+(vr-vl)/2;
        return max(sum1((v<<1)+1,vl,mid,l,r),sum1((v<<1)+2,mid+1,vr,l,r));
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        a.resize(n);
        ll mx=-1;
        rep(i,n) {
            cin >> a[i];
            mx=max(mx,a[i]);
        }
        int m;
        cin>>m;
        ll mx1=-1;
        vector <pair <ll,ll> > b(m);
        rep(i,m) {
            cin >> b[i].second >> b[i].first;
            mx1=max(mx1,b[i].second);
        }
        vector <ll> d(m);
        sort(b.begin(),b.end());
        for (int i=0;i<m;i++)
            d[i]=b[i].first;
        c.resize(m);
        for (int i=0;i<m;i++)
            c[i]=b[i].second;
     //   cout<<mx1<<'\n';
        if (mx1<mx)
        {
            cout<<-1<<'\n';
            continue;
        }
        built(0,0,m-1);
        built1(0,0,n-1);
        int j=0;
        int cnt=0;
        while (j<n)
        {
            ll l=0,r=n-j;
            ll ans;
            while (l<=r)
            {
              ll mid=(l+r)/2;
              ll v=sum1(0,0,n-1,j,j+mid-1);
               auto k=lower_bound(d.begin(),d.end(),mid);
               if (k==d.end())
                   r=mid-1;
               else{
                   int q=k-d.begin();
              ll u=sum(0,0,m-1,q,m-1);
              //cout<<j<<" "<<u<<" "<<v<<'\n';
              if (u>=v)
              {
                  ans=mid;
                  l=mid+1;
              }
              else
                  r=mid-1;
            }}
            //cout<<ans<<" ";
            cnt++;
            j+=ans;
        }
        cout<<cnt<<'\n';
    }
 
}