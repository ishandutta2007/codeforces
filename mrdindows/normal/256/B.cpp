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
#define mod 1000000009
#define maxll 0x7fffffffffffffffLL
const int D=10000;
double solve(ll a,ll b,ll c)
{
//  cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
    if (a==0)
    {
        return 1.*-c/b;
    }
    ll d=b*b-4*a*c;
    
    return (-b+sqrt(d))/(2*a);
}

int main()
{
    int n,x,y,c;
    scanf("%d%d%d%d",&n,&x,&y,&c);
    int a[5];
    a[0]=x-1;
    a[1]=y-1;
    a[2]=n-x;
    a[3]=n-y;
    int b[5];
    a[4]=b[4]=1000000000;
    for (int i=0;i<4;i++)
        b[i]=a[i]+a[(i+1)%4];
    sort(a,a+4);
    sort(b,b+4);
    int cura=0,curb=0;
    ll s=1;
    ll da=4;
    ll sp=4;
    ll t=0;
    ll nexts=s;
    ll lasta=da;
    ll lastsp=sp;
    ll p=0;
    while (nexts<c)
    {
        t+=p;
        s=nexts;
        lasta=da;
        lastsp=sp;
        p=min(a[cura],b[curb])-t;
        nexts+=p*(2*sp+da*(p-1))/2;
        sp+=da*p;
        if (a[cura]<b[curb])
        {
            cura++;
            da-=2;
            sp-=1;
        }
        else
        {
            da+=1;
            curb++;
        }
    }
    double m=solve(lasta,2*lastsp-lasta,2*(s-c))-1E-5;
    int o=t+(int)(m+0.9999999);
    cout<<o<<endl;
    return 0;
}