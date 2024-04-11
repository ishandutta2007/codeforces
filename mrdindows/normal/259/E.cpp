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
typedef unsigned short us;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<int, bool> pib;

#define maxll 0x7fffffffffffffffLL
#define mod 1000000007
#define INF 1000000000
ll binpow(ll a, ll n)
{
    ll res=1;
    while(n>0)
    {
        if (n&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    ll s=1;
    int *k=new int[100001];
    int max=0;
    for (int i=0;i<100001;i++)
    {
        k[i]=0;
    }
    int x;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        k[x]++;
        if (x>max)
            max=x;
    }

    int *pref=new int[100002];
    pref[0]=0;
    for (int i=1;i<100001;i++)
    {
        pref[i]=pref[i-1]+k[i];
    }
    ll t;
    int *b=new int[1000];
    int *v=new int[1000];
    for (int i=2;i<=max;i++)
    {
        int vs=0;
        int bs=0;
        b[bs++]=100001;
        for (int j=1;j*j<=i;j++)
        {
            if (i%j==0)
            {
                v[vs++]=(j);
                if (j*j!=i)
                {
                    b[bs++]=(i/j);
                }
            }
        }
        v[vs++]=(b[bs-1]);
        t=1;
        int z=pref[100000]-pref[i-1];
        for (int j=0;j<vs-1;j++)
        {
            int u=pref[v[j+1]-1]-pref[v[j]-1];
            t=(t*binpow(j+1,u))%mod;
        }
        for (int j=2;j<bs;j++)
        {
            int u=pref[b[j-1]-1]-pref[b[j]-1];
            t=(t*binpow(vs+bs-j-1,u))%mod;
        }
        ll p=vs+bs-2;
        t=(t*((binpow(p,z)+mod-binpow(p-1,z))%mod))%mod;

        s=(s+t)%mod;
    }
    cout<<s<<endl;
    return 0;
}