#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<math.h>
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
//#define flush {cout.flush();fflush(stdout);}
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x));
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]));
#define random(x) (((rand()<<15)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 qstupid_cmath_make_me_cry
#define tm stupid_ctime
#define pb push_back
#define mp make_pair
//#define long long long
#include<map>
#include<set>
#include<queue>
//const unsigned long long mod=(long long)1000000*1000000+7;
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include<cassert>
using namespace std;

typedef long long lli;
typedef long double ld;
typedef unsigned long long ulli;
typedef unsigned int ui;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
const int INF=1;
ll *pref=new ll[100001];
ll sum(int a,int b)
{
    if (a==0)
        return pref[b];
    else
        return pref[b]-pref[a-1];
}
int main()
{   
    int n,t;
    cin>>n>>t;
    int *a=new int[n+1];
    for (int i=0;i<n;i++)
        scanf("%d",&(a[i]));
    sort(a,a+n);
    pref[0]=a[0];
    for (int i=1;i<n;i++)
        pref[i]=pref[i-1]+a[i];
    a[n]=a[n-1]+1;

    int max=1;
    int num=a[0];
    for (int i=1;i<n;i++)
    {
        int l=0;
        int r=i;
        while (l!=r)
        {
            int m=(l+r)/2;
            if (sum(m,i)+t>=(ll)a[i]*(i-m+1))
            {
                r=m;
            }
            else
            {
                l=m+1;
            }
        }
        if (i-r+1>max)
            max=i-r+1,num=a[i];
    }

    cout<<max<<" "<<num<<endl;
    return 0;
}