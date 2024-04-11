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
typedef long long lli;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() 
{
    lli *a=new lli[5];
    lli n;
    cin>>n;
    lli *p=new lli[n];
        for (int i=0;i<n;i++)
    {
        cin>>p[i];
        }
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    lli k[5]={0,0,0,0,0};
    lli s=0;
    for (int i=0;i<n;i++)
    {
        s+=p[i];
        for (int j=4;j>=0;j--)
        {
            if (s>=a[j])
            {
                k[j]+=s/a[j];
                s%=a[j];
            }
        }
    }
    for (int i=0;i<5;i++)
        cout<<k[i]<<((i<4)?" ":"\n");
    cout<<s<<endl;
    return 0;
}