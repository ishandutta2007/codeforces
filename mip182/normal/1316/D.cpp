#include <bits/stdc++.h>
//#pragma GCC optmize("Ofast")
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
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int par[MAXN],ranks[MAXN],sz[MAXN];
int x[MAXN],y[MAXN];
vector <int> xx={0,0,1,-1};
vector <int> yy={1,-1,0,0};
int n;
char ans[1000][1000];
int used[1000][1000];
int usedd[1000][1000];
void make_set(int s)
{
    ranks[s]=0;
    par[s]=s;
    sz[s]=1;
}
int find_set(int s)
{
    if (par[s]==s)
        return s;
    return par[s]=find_set(par[s]);
}
void union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if (a!=b)
    {
        if (ranks[a]<ranks[b])
            swap(a,b);
        if (ranks[a]==ranks[b])
            ranks[a]++;
        par[b]=a;
        sz[a]+=sz[b];
    }
}
void check(int a,int b)
{
    if (usedd[a][b]==1)
        return;
    usedd[a][b]=1;
    for (int i=0;i<4;i++)
    {
      //  cout<<a<<" "<<b<<" "<<a+xx[i]<<" "<<b+yy[i]<<'\n';
        if (a+xx[i]>=0&&a+xx[i]<n&&b+yy[i]<n&&b+yy[i]>=0&&x[a+b*n]==x[(a+xx[i])+(b+yy[i])*n]&&y[a+n*b]==y[(a+xx[i])+(b+yy[i])*n])
        {
            union_sets(a+n*b,(a+xx[i])+(b+yy[i])*n);
        }
    }
}
void thing(int a,char c)
{
   // cout<<a<<'\n';
    if (used[a/n][a%n]==1)
        return;
    ans[a/n][a%n]=c;
    used[a/n][a%n]=1;
    int b=a/n;
    a%=n;
    for (int i=0;i<4;i++)
    {
        if (a+xx[i]>=0&&a+xx[i]<n&&b+yy[i]<n&&b+yy[i]>=0&&x[a+b*n]==x[(a+xx[i])+(b+yy[i])*n]&&y[a+b*n]==y[(a+xx[i])+(b+yy[i])*n]&&used[b+yy[i]][a+xx[i]]==0)
        {
            if (xx[i]==1&&yy[i]==0)
            {
                thing((a+xx[i])+(b+yy[i])*n,'L');
            }
            if (xx[i]==-1&&yy[i]==0)
            {
                thing((a+xx[i])+(b+yy[i])*n,'R');
            }
            if (xx[i]==0&&yy[i]==1)
            {
                thing((a+xx[i])+(b+yy[i])*n,'U');
            }
            if (xx[i]==0&&yy[i]==-1)
            {
                thing((a+xx[i])+(b+yy[i])*n,'D');
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    cin>>n;
    for (int i=0;i<n*n;i++)
        make_set(i);
    for (int i=0;i<n*n;i++)
    {
            cin>>y[i]>>x[i];
            x[i]--,y[i]--;
//            if (i==11)
//                cout<<x[i]<<" "<<y[i]<<'\n';
    }
    for (int i=0;i<n*n;i++)
    {
            check(i%n,i/n);
    }
//    for (int i=0;i<n;i++)
//    {
//        for (int j=0;j<n;j++)
//            cout<<find_set(i*n+j)<<" ";
//        cout<<'\n';
//    }
    bool ok=true;
    for (int i=0;i<n*n;i++)
    {
            if (x[i]==-2&&y[i]==-2)
            {
                if (sz[find_set(i)]==1)
                    ok=false;
            }
            else
            {
                if (find_set(x[i]+n*y[i])!=find_set(i%n+(i/n)*n))
                {
                    ok=false;
                }
                if (x[i]!=x[(x[i]+n*y[i])]||y[i]!=y[(x[i]+n*y[i])]) {
              //      cout<<x[i]<<" "<<y[i]<<'\n';
               //     cout<<x[x[i]+n*y[i]]<<" "<<y[x[i]+n*y[i]]<<'\n';
                    ok = false;
                }

            }
    }
    if (ok==false)
    {
        cout<<"INVALID";
        return 0;
    }
    cout<<"VALID\n";
    for (int i=0;i<n*n;i++)
    {
            if (i%n==x[i]&&i/n==y[i]) {
                thing(i,'X');
            }
    }
    for (int i=0;i<n*n;i++)
    {
            if (x[i]==-2&&y[i]==-2&&used[i/n][i%n]==0)
            {
                //cout<<i/n<<" "<<i%n<<'\n';
                if (i%n+0>=0&&i%n+0<n&&i/n+1<n&&i/n+1>=0&&x[i]==x[i+n]&&y[i]==y[i+n])
                {
                    thing(i,'D');
                }
                else
                {
                    if (i%n+0>=0&&i%n+0<n&&i/n-1<n&&i/n-1>=0&&x[i]==x[i-n]&&y[i]==y[i-n])
                    {
                        thing(i,'U');
                    } else
                    {
                        if (i%n+1>=0&&i%n+1<n&&i/n<n&&i/n>=0&&x[i]==x[i+1]&&y[i+1]==y[i])
                        {
                            thing(i,'R');
                        }
                        else
                            thing(i,'L');
                    }
                }

            }
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            cout<<ans[i][j];
        cout<<'\n';
    }



}