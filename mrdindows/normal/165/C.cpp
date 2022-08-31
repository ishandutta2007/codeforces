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

int main()
{

    int k;
    cin>>k;
    int n=0;
    lli s=0;
    char c;
    int i=0;
    bool f=false;
    int first;
    int *b=new int[1000000];
    int q=1;
    b[0]=-1;
    if (k==0)
    {
        int t=0;
            while (scanf("%c",&c)!=EOF)
    {
        if (c=='1' || c=='0')
        {
            if (c=='0')
                s+=(++t);
            else
                t=0;


        }
            }
    }
    else
    while (scanf("%c",&c)!=EOF)
    {
        if (c=='1' || c=='0')
        {
        if (c=='1') 
        {
            b[q++]=i;
        }
            if (q>k)
            {
                s+=b[q-k]-b[q-k-1];
            }
        

        i++;
        }
    }
    cout<<s;
    return 0;
}