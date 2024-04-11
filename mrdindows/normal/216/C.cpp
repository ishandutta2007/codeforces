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
long double const d=pow(10.0,-10);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[n+m];
    int end[n+m];
    int t=k;
    vector<int> v(k,0);
    fill(a,0);
    fill(end,0);
    for (int i=0;i<n;i++)
        a[i]=k;
    end[n-1]=k;
    for (int i=n-1;i<n+m;i++)
    {
    //    cout<<"i="<<i<<" a[i]="<<a[i]<<" end[i]="<<end[i]<<endl;
        int s=k-a[i];
        if (s>0)
        {
            for (int j=0;j<s;j++)
                v.push_back(i);
            for (int j=0;j<n;j++)
                a[(i+j)%(n+m)]+=s; 
                end[i+n-1]+=s;
        }
        if (end[i]==a[i])
        {
            v.push_back(i);
            for (int j=0;j<n;j++)
                a[(i+j)%(n+m)]++; 
            end[i+n-1]++;
        }
    }
    cout<<v.size()<<endl;
    for (int i=0;i<v.size();i++)
        cout<<v[i]+1<<" ";
   //     system("pause");
    return 0;
}