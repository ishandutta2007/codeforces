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
typedef pair<int, bool> pib;

const int D=100;
const int INF = 1000000000;

using namespace std;
bool go(int a,int b)
{
    int x;
    while (a>0)
    {
        x=a%10;
        a/=10;
        int c=b;
        while(c>0)
        {
            if (c%10==x) return true;
            c/=10;
        }
    }



    return false;
}
int main()
{
    int n;
    cin>>n;
    if (n==1 || n==2)
    {
        cout<<1<<endl;
        return 0;
    }
    
    int k=0;
    for (int i=1;i<sqrt(n);i++)
    {
        if (n%i==0)
        {
            if (go(n,i))
                k++;
            if (go(n,n/i))
                k++;
        }
    }
    if (sqr((int)(sqrt(n)+0.000001))==n)
    {
        if (go(n,(sqrt(n))+0.0000001))
            k++;
    }
    cout<<k<<endl;
    return 0;
}