#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<vector>
#include<ctime>
#include<memory.h>
#include<algorithm>
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt((x)*1.)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
//#define flush {cout.flush();fflush(stdout);}
#define random(x) (((rand()<<15)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 qstupid_cmath_make_me_cry
#define tm stupid_ctime
#define pb push_back
#define mp make_pair
//#define long long long
#include<map>
#include<set>
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 using namespace std;

typedef unsigned long long lli;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

const int D=100;
const int INF = 1000000000;

using namespace std;
void NO()
{
    cout<<"NO"<<endl;
    exit(0);
}
void YES()
{
    cout<<"YES"<<endl;
    exit(0);
}
int main()
{
    int n,m;
    cin>>n>>m;
    int *a=new int[n];
    vector<pii> *u=new vector<pii>[n];
    vector<int> *b=new vector<int>[n+1];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&(a[i]));
        if (a[i]<=n)
        b[a[i]].push_back(i);
    }
    int total=0;
    for (int i=1;i<=n;i++)
    {
        if (b[i].size()>=i)
        {
            for (int j=0;j+i-1<b[i].size();j++)
            {
                int f=b[i][j+i-1];
                int g=(j==0)?-1:b[i][j-1];
                int h=(j+i==b[i].size())?n:b[i][j+i];
                for (int t=g+1;t<=b[i][j];t++)
                {
                    u[t].push_back(mp(f,h));
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        sort(u[i].begin(),u[i].end());
    }
    int x,y;
    for (int st=0;st<m;st++)
    {
        cin>>x>>y;
        x--;
        y--;
        int k=0;
        for (int i=0;i<u[x].size() && u[x][i].first<=y;i++)
        {
            if (u[x][i].second>y)
            {
                k++;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}