#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<memory.h>
#include<algorithm>
#include<string>
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
typedef long long LL;

int main()
{  
    int n;
    int m;
    int p=-1;
    cin>>n>>m;
    bool **a=new bool*[n+4];
    for (int i=0;i<n+4;i++)
    {
        a[i]=new bool[n+4];
        for (int j=0;j<n+4;j++)
            a[i][j]=false;
    }
    bool c=false;
        for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x+1][y+1]=true;
        if (!c)
        {
        for (int j=0;j<9;j++)
        {
            bool e=true;
            for (int k=0;k<9;k++)
                if(!a[x+1-j/3+k/3][y+1-j%3+k%3])
                    e=false;
            if (e) 
            {
                    p=i+1;
                    c=true;
            }
        }
        }
                
    }
    cout<<p;
    return 0;
}