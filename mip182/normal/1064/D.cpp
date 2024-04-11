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
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vector <int> xx={0,0,1,-1},yy={1,-1,0,0};
int n,m;
char a[2000][2000];
vector <int> d;
void bfs(int s)
{
    d=vector <int> (n*m,INF);
    d[s]=0;
    deque<int> q;
    q.pb(s);
    while (!q.empty())
    {
        //  cout<<q.size()<<'\n';
        int f=q.front();
        q.pop_front();
        int xxx=f%m,yyy=f/m;
        for (int i=0;i<4;i++)
        {
            if (xxx+xx[i]>=0&&xxx+xx[i]<m&&yyy+yy[i]<n&&yyy+yy[i]>=0&&a[xxx+xx[i]][yyy+yy[i]]=='.')
            {
                //    cout<<a[xxx+xx[i]][yyy+yy[i]]<<" "<<xxx<<" "<<yyy<<" "<<xxx+xx[i]<<" "<<yyy+yy[i]<<'\n';
                if (xx[i]==-1)
                {
                    if (d[xxx+xx[i]+m*(yyy+yy[i])]==INF)
                    {
                        d[xxx+xx[i]+m*(yyy+yy[i])]=d[f]+1;
                        q.pb(xxx+xx[i]+m*(yyy+yy[i]));
                        continue;
                    }
                    if (d[xxx+xx[i]+m*(yyy+yy[i])]>d[f]+1){
                        d[xxx+xx[i]+m*(yyy+yy[i])]=d[f]+1;
                        q.push_front(xxx+xx[i]+m*(yyy+yy[i])); }
                } else {
                    if (d[xxx+xx[i]+m*(yyy+yy[i])]>d[f]) {
                        q.push_front(xxx + xx[i] + m * (yyy + yy[i]));
                        d[xxx + xx[i] + m * (yyy + yy[i])] = d[f];
                    }
                }
            }
        }
    }
}
int main() {
    //  ios_base::sync_with_stdio(0);
    // cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    cin>>n>>m;
    int x,y;
    int r,c;
    cin>>r>>c;
    r--,c--;
    cin>>x>>y;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for (int j=0;j<m;j++)
            a[j][i]=s[j];
    }
    bfs(c+r*m);
    // cout<<"ahha";
//    for (int i=0;i<n;i++)
//    {
//        for (int j=0;j<m;j++)
//            cout<<d[j+i*m]<<" ";
//        cout<<'\n';
//    }
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (d[j+i*m]!=INF)
            {
                //      cout<<j<<" "<<i<<" "<<d[j+i*m]<<" "<<j+d[j+i*m]-c<<" "<<x<<" "<<y<<'\n';
                if (d[j+i*m]<=x&&j+d[j+i*m]-c<=y) {
                    cnt++;
                    //        cout<<i<<" "<<j<<'\n';
                }
            }
        }
    }
    cout<<cnt;





}