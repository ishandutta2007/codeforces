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


    lli n,k;
    lli l;
lli *p=new lli[100];
void search(lli le,lli r)
{
    if (le==r)
    {
        cout<<le;
        return;
    }
    lli i=(le+r)/2;
    lli s=0;
    for (int j=0;j<=l;j++)
    {
        if (i/p[j]==0) 
        {
            if (s>=n)
            {
                search(le,i);
                return;
            }
            else
            {
                search(i+1,r);
                return;
            }
        }
        else
        s+=i/p[j];
    }
}




int main()
{   

    cin>>n>>k;
    lli c=1;
    if (n==1 && k==2)
    {

        cout<<1;
        return 0;
    }
    for (lli i=0;i<n+15;i++)
    {
        p[i]=c;
        if (c>=k*n)
        {

            l=i;
            break;
        }
        c*=k;
    }
    search(1,n*k+1);

    return 0;
}