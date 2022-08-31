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
#define pb push_back
#define mp make_pair
//#define long long long
#include<map>
#include<set>
#include<bitset>
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 using namespace std;

typedef unsigned long long lli;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int D=100;



lli step[20];
int main()
{
    step[0]=1;
    for (int i=1;i<20;i++)
        step[i]=step[i-1]*10;
    lli n,k;
    cin>>n>>k;
    n++;
    lli x=n;
    for (int i=1;i<=19;i++)
    {
        long long r=x-x/step[i]*step[i];
        if (r>k) { cout<<x/step[i-1]*step[i-1]-1<<endl;break;}
    }
    return 0;
}