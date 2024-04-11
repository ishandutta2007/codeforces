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
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
//#define long long long
#include<map>
#include<set>
#include<bitset>
//typedef pair<int,int> pii;
//typedef vector<int> vi;
//typedef vector<pii> vpii;
#define mod 1000000007
 typedef long long lli;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int D=100;

using namespace std;
int main()
 {
     int n,m;
     cin>>n>>m;
     int *a=new int[m];
     int *b=new int[m];
     for (int i=0;i<m;i++)
     {
         cin>>a[i];
         b[i]=a[i];
     }
     int minsum=0;
     int maxsum=0;
     for (int i=0;i<n;i++)
     {
         int max=a[0];
         int imax=0;
         for (int j=0;j<m;j++)  
             if (a[j]>max) {imax=j;max=a[j];}
         a[imax]--;
         maxsum+=max;
     }
     for (int i=0;i<n;i++)
     {
         int max=100000;
         int imax=-1;
         for (int j=0;j<m;j++)  
             if (b[j]<max && b[j]>0) {imax=j;max=b[j];}
         b[imax]--;
         minsum+=max;
     }
     cout<<maxsum<<" "<<minsum<<endl;

   // system("pause");
    return 0;
 }