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
     vector<short> v[3];
     int n;
     cin>>n;
     int sum=n;
     int *a=new int[n];
     int *k=new int[n];

     int **b=new int*[n];
     for (int i=0;i<n;i++)
     {
         cin>>a[i];
         a[i]--;
         v[a[i]].push_back(i);
     }
     for (int i=0;i<n;i++)
     {
         cin>>k[i];
         b[i]=new int[k[i]];
         for (int j=0;j<k[i];j++)
         {
             cin>>b[i][j];
             b[i][j]--;
         }
     }
     if (n==1)
     {
         cout<<1<<endl;
         return 0;
     }

     int min=20000000;
     for (int qwe=0;qwe<3;qwe++)
     {
            bool *used=new bool[n];
            for (int i=0;i<n;i++)
                 used[i]=false;
         int current=qwe;
     for (int i=0;i<2*n+2;i++)
     {
         for (int j=0;j<v[current].size();j++)
         {
             int x=v[current][j];
             if (!used[x])
             {
                bool e=true;
                for (int q=0;q<k[x];q++)
                    e=(e && used[b[x][q]]);
                if (e)
                {
                    used[x]=true;
                    j=-1;
                }
             }
         }
         bool e=true;
         for (int q=0;q<n;q++)
             e=(e && used[q]);
         if (e)
         {
             if (i<min)
                 min=i;
             break;
         }
         current=(current+1)%3;
     }
     }
     cout<<sum+min<<endl;
    return 0;
 }