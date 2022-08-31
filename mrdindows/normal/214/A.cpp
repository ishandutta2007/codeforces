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
#define y0 qstupid_cmath_make_me_cry
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
     int n,m;
     cin>>n>>m;
     int k=0;
    for (int i=0;i<n+1000;i++)
        for (int j=0;j<m+1000;j++)
        {
            if (i*i+j==n &&  j*j+i==m)
                k++;
        }
        cout<<k<<endl;
    return 0;
 }