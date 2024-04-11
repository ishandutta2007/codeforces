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


int n,k;
long long prod(long long a, long long b)
{
    return ((a % mod) *(b % mod)) % mod;
}
long long sum(long long a, long long b)
{
    return (a+b) % mod;
}
long long step(long long x,long long n)
{
    long long a=1;
    while (n)
    {
        if (n&1)
            a=prod(a,x);
        n>>=1;
        x=prod(x,x);
    }
    return a;
}
long long obr(long long x)
{
    return step(x,mod-2);
}
long long st[2001];
long long pw[2001];
int main()
{
    cin>>n>>k;
    int a[2000];
    for (int i=0;i<n;i++)
        cin>>a[i];
    st[0]=k;
    pw[0]=1;
    for (int i=1;i<=n;i++)
    {
        st[i]=prod(st[i-1],k+i);
        pw[i]=prod(pw[i-1],i);
    }
    for (int i=2;i<=n;i++)
    {
        pw[i]=obr(pw[i]);
    }
    long long b[2001];
    for (int i=0;i<n;i++)
    {
        b[i]=a[i];
        for (int j=0;j<i;j++)
        {
            //cout<<st[i-j]<<" "<<pw[i-j]<<" "<<endl;
            b[i]=sum(b[i],prod(a[j],prod(st[i-j-1],pw[i-j])));
        }
    }
    for (int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}