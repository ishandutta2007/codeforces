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
#define fill(m,v) memset(m,v,sizeof(m))
//#define flush {cout.flush();fflush(stdout);}
#define random(x) (((rand()<<15)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
//#define long long long
#include<map>
#include<set>
using namespace std;
#define mod 1000000007
typedef unsigned long long lli;

lli step(int k)
{
    lli c=1;
    for (int i=0;i<k;i++)
        c*=10;
    return c;

}
lli count(lli x)
{
    if (x==0)
        return 0;
    if (x<10) return x;
    if (x%10==9) x++;
    lli s=0;
    lli c=9;
    lli tr=x;
    int k=0;
    while (tr>=10)
    {
        tr/=10;
        k++;
    }
    if (k>0)
        s=9;
    for (int i=1;i<k;i++)
    {
        s+=c;
        c=c*10;
    }
    lli t=step(k);
    lli y=2*t;
    while (x>y)
    {
            s+=step(k-1);
            y+=t;
    }
    int l=(x/step(k));

    x=x+t-y;
    if (x%10>=l) s++;
    s+=x/10;
    return s;
}
int main()
{
    lli a,b;
    cin>>a>>b;
    cout<<count(b)-count(a-1);
    return 0;
}