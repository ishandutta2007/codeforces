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
     int n,k;
     cin>>n>>k;
     int *a=new int[2*n+1];
     for (int i=0;i<2*n+1;i++)
         cin>>a[i];
     for (int i=1;i<2*n+1 && k>0;i+=2)
         if (a[i]>a[i-1]+1 && a[i]>a[i+1]+1) {a[i]--;k--;}
     for (int i=0;i<2*n+1;i++)
         cout<<a[i]<<" ";
    cout<<endl;
   // system("pause");
    return 0;
 }