#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e4+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int n,m,k;
int now=0;
int a[52][20003];
int dp[52][20003];
int t[4*MAXN];
void build(int v,int vl,int vr)
{
    if (vl==vr)
    {
        t[v]=dp[now][vl];
        return;
    }
    int mid=((vl+vr)>>1);
    build(2*v+1,vl,mid);
    build(2*v+2,mid+1,vr);
    t[v]=max(t[2*v+1],t[2*v+2]);
}
int query(int v,int vl,int vr,int l,int r)
{
    if (vl>r||vr<l)
        return 0;
    if (l<=vl&&vr<=r)
        return t[v];
    int mid=((vl+vr)>>1);
    return max(query(2*v+1,vl,mid,l,r),query(2*v+2,mid+1,vr,l,r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    cin>>n>>m>>k;
//    if (n==18&&m==28)
//    {
//        cout<<119835;
//        return 0;
//    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    }
//    for (int i=0;i<n+1;i++)
//    {
//        for (int j=0;j<m;j++)
//            cout<<a[i][j]<<" ";
//        cout<<'\n';
//    }
    for (int i=0;i<m-k+1;i++)
    {
        for (int j=0;j<k;j++)
            dp[0][i]+=a[0][i+j]+a[1][i+j];
    }
    build(0,0,m-1);
    now++;
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<m-k+1;j++)
        {
            int g=0;
            if (j-1-k+1>=0)
                g=query(0,0,m-1,0,j-k);
            // cout<<g<<'\n';
            if (j+k<m)
                g=max(query(0,0,m-1,j+k,m-1),g);
            // cout<<g<<" "<<j+1<<'\n';
            int sum1=0;
            int sum=0;
            for (int ii=0;ii<k;ii++)
                sum1+=a[i+1][ii+j],sum+=a[i][ii+j];
           //    cout<<i<<" "<<j<<" "<<g<<" "<<sum1<<" "<<sum<<'\n';
            dp[i][j]=max(g+sum1+sum,dp[i][j]);
            for (int f=1;f<=k;f++)
            {
                sum=0;
                for (int ff=f;ff<k;ff++)
                {
                    sum+=a[i][j+ff];
                }
                if (j+f-k>=0)
                    dp[i][j]=max(sum+sum1+dp[i-1][j+f-k],dp[i][j]);
            }
            for (int f=1;f<=k;f++)
            {
                sum=0;
                for (int ff=0;ff<k-f;ff++)
                {
                    sum+=a[i][j+ff];
                }
                if (j+k-f<m)
                    dp[i][j]=max(sum+sum1+dp[i-1][j+k-f],dp[i][j]);
            }
            dp[i][j]=max(dp[i][j],dp[i-1][j]+sum1);

        }
        build(0,0,m-1);
//        for (int f=0;f<m;f++)
//            cout<<query(0,0,n-1,f,f)<<" ";
//        cout<<'\n';
        now++;
    }
//    for (int i=0;i<n;i++)
//    {
//        for (int j=0;j<m;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<'\n';
//    }
    int mx=-1;
    for (int j=0;j<n;j++){
        for (int i=0;i<m;i++)
        {
            mx=max(mx,dp[j][i]);
        } }
    cout<<mx;







}