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
int r[]={0,31,  28,31,  30, 31, 30, 31, 31, 30, 31  ,30,    31};
int main()
{
    map<int,int> m;
    char* s=new char[100001];
    for (int i=0;i<100001;i++)
        s[i]=0;
    int t[14];
    t[0]=0;
    for (int i=1;i<=13;i++)
    {
        t[i]=t[i-1]+r[i-1];
    }
    cin>>s;
    int a,b,c;
    int n=strlen(s);
    for (int i=0;i<=n-10;i++)
    {
        bool e=true;
        for (int j=0;j<10;j++)
        {
            if (j==2 || j==5)
            {
                if (s[i+j]!='-')
                {
                    e=false;
                    break;
                }
            }
            else
            {
                if (!isdigit(s[i+j]))
                {
                    e=false;
                    break;
                }
            }
        }
        if (e)
        {
            char q=s[i+10];
            s[i+10]=0;
            sscanf(s+i,"%d-%d-%d",&a,&b,&c);
            
            //cout<<a<<" "<<b<<" "<<c<<endl;
            s[i+10]=q;
            if (b<=0 || b>12 || c<2013 || c>2015 || a>r[b] || a==0)
            {
                continue;
            }
            else
            {
                int p=t[13]*(c-2013)+t[b]+a-1;
                m[p]++;
            }
            
        }
    }
    int max=0;
    int maxi=0;
    bool z=false;
    for (int i=0;i<2000;i++)
    {
        int t=m[i];
        if (t>max)
        {
            z=true;
            max=t;
            maxi=i;
        }
        else
        {
            if (t==max)
            {
                z=false;
            }
        }
    }
    c=maxi/t[13]+2013;
    maxi=maxi%(t[13])+1;

    int k=0;
    while (maxi>t[k+1])k++; 
    int q=maxi-t[k];
    if (q<10)
    {
        cout<<0<<q<<"-";
    }
    else
    {
        cout<<q<<"-";
    }
    if (k<10)
    {
        cout<<0<<k<<"-";
    }
    else
    {
        cout<<k<<"-";
    }
    cout<<c<<endl;


    return 0;
}