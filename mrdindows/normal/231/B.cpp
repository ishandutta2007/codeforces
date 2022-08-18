#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<math.h>
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
#include<queue>
//const unsigned long long mod=(long long)1000000*1000000+7;
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include<cassert>
using namespace std;

typedef long long lli;
typedef long double ld;
typedef unsigned long long ulli;
typedef unsigned int ui;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
const int INF=1;

int main()
{   
    int n,l,d;
    cin>>n>>d>>l;
    int *a=new int[101];
    a[0]=d;
    bool e=true;
    if (d<0)
        e=false,d=-d;
    for (int i=0;i<n;i++)
    {
        if ((i+e)%2)
        {
            int r=min(d+1,l);
            a[i]=r;
            d-=r;
        }
        else
        {
            a[i]=1;
            d++;
        }
    }
    if (d==-1)
    {
        for (int i=0;i<n;i++)
        {
                    if ((i+e)%2 && a[i]>1)
                    {a[i]--;break;}
                    if ((i+e)%2==0 && a[i]<l)
                    {a[i]++;break;}
        }

    }
    if (d>0)
        cout<<-1;
    else
        for (int i=0;i<n;i++)
            cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}