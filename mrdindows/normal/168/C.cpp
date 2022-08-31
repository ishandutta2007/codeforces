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
typedef pair<int,int> PII;
int main()
{   
    int n,a,d;
    cin>>n>>a>>d;
    int *p=new int[n];
    int *v=new int[n];
    for (int i=0;i<n;i++)
        cin>>p[i]>>v[i];
    double *t=new double[n];
    for (int i=0;i<n;i++)
    {
        double k=(double)v[i]/a;
        double r=(double)a*k*k*0.5;
        if (r>d)
        {
            t[i]=p[i]+sqrt(2*(double)d/a);
        }
        else
        {
            t[i]=p[i]+k+(d-r)/v[i];
        }
        if (i>0)
            if (t[i]<t[i-1]) t[i]=t[i-1];
    }
    cout<<fixed;
    for (int i=0;i<n;i++)
        cout<<t[i]<<endl;
    return 0;
}