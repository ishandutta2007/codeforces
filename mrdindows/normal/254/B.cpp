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
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x));
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]));
#define random(x) (((rand()*25)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 qstupid_cmath_make_me_cry
#define tm stupid_ctime
#define pb push_back
#define mp make_pair
#include<map>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#pragma comment(linker,"/STACK:256000000")
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<int, bool> pib;

#define maxll 0x7fffffffffffffffLL
#define mod 1073741824//1000000009

#pragma comment(linker,"/STACK:256000000")


int v[]={31, 28,    31, 30, 31, 30, 31, 31  ,30 ,31,    30, 31};
int r[700];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int m[101];
    int d[101];
    int p[101];
    int t[101];
    for (int i=0;i<700;i++)
        r[i]=0;
    for (int i=0;i<n;i++)
    {
        cin>>m[i]>>d[i]>>p[i]>>t[i];
        int s=d[i];
        for (int j=0;j<m[i]-1;j++)
        {
            s+=v[j];
        }
        for (int j=1;j<=t[i];j++)
        {
            r[s+150-j]+=p[i];
        }
    }
    int max=0;
    for (int i=0;i<700;i++)
    {
//      if (r[i]>0)
//      {
//          cout<<r[i]<<" "<<i<<endl;
//      }
        if (r[i]>max)
        {
            max=r[i];
        }
    }
    cout<<max<<endl;
    return 0;
}