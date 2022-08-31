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
    int n;
    cin>>n;
    int *x=new int[n];
    int *y=new int[n];
    for (int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    int t=0;
    for (int i=0;i<n;i++)
    {
        int e[4]={0,0,0,0};
        for (int j=0;j<n;j++)
        {
            if (i!=j)
            {
                if (x[j]<x[i] && y[j]==y[i])
                e[0]=1;
                if (x[j]>x[i] && y[j]==y[i])
                e[1]=1;
                if (x[j]==x[i] && y[j]>y[i])
                e[2]=1;
                if (x[j]==x[i] && y[j]<y[i])
                e[3]=1;
            }
        }
        int k=1;
        for (int q=0;q<4;q++)
            k*=e[q];
        t+=k;
    }
    cout<<t;
    return 0;
}