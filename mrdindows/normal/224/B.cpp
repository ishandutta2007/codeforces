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
#define max(a,b,c) max(max((a),(b)),(c))
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
//#define flush {cout.flush();fflush(stdout);}
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x));
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]));
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
//const unsigned long long mod=(long long)1000000*1000000+7;
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 using namespace std;

typedef long long lli;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

bool *u=new bool[100001];
int main()
{
    int n,k;
    cin>>n>>k;
    int *a=new int[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&(a[i]));
    }
    for (int i=0;i<100001;i++)
        u[i]=false;
    int t=0;
    int res=n;
    for (int i=0;i<n;i++)
    {
        if (!u[a[i]])
        {
            t++;
            u[a[i]]=true;
            if (t==k)
            {
                res=i;
                break;
            }
        }
    }
    if (res==n)
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    t=0;
    for (int i=0;i<100001;i++)
        u[i]=false;
    int res2=0;
    for (int i=res;i>=0;i--)
    {
        if (!u[a[i]])
        {
            t++;
            u[a[i]]=true;
            if (t==k)
            {
                res2=i;
                break;
            }
        }
    }
    cout<<res2+1<<" "<<res+1<<endl;
    return 0;
}