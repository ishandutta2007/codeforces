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
const int INF=1000000000;
long long gcd (long long a, long long b) 
{
    while (b) {
        a %= b;
        swap (a, b);
    }
    return a;
}
long long lcm (long long a, long long b) 
{
    return a / gcd (a, b) * b;
}
char *a[100];
long long *b[100];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        a[i]=new char[m];
        b[i]=new long long[m];
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            b[i][j]=INF;
        }
    }
    for (int i=0;i<n;i++)
    {
        long long p=40000;
        long long t=40000;
        int first=-1;
        int last=m;
        for (int j=0;j<m;j++)
        {
            if (a[i][j]=='1')
            {
                b[i][j]=0;
                p=0;
                last=j;
            }
            else
            {
                p++;
                if (b[i][j]>p)
                {
                    b[i][j]=p;
                }
            }
            if (a[i][m-j-1]=='1')
            {
                b[i][m-j-1]=0;
                t=0;
                first=m-j-1;
            }
            else
            {
                t++;
                if (b[i][m-j-1]>t)
                {
                    b[i][m-j-1]=t;
                }

            }
        }
        if (first<0 || last>=m)
        {
            cout<<-1<<endl;
            //system("pause");
            return 0;
        }
        for (int j=m-1;j>last;j--)
        {
            if (b[i][j]>first+m-j)
                b[i][j]=first+m-j;
        }
        for (int j=0;j<first;j++)
        {
            if (b[i][j]>m-last+j)
                b[i][j]=m-last+j;
        }
        
    }
//  for (int i=0;i<n;i++,cout<<endl)
//      for (int j=0;j<m;j++)
//          cout<<b[i][j];
    long long min=INF,jmin=0;
    for (int i=0;i<m;i++)
    {
        long long s=0;
        for (int j=0;j<n;j++)
        {
            s+=b[j][i];
        }
        if (s<min)
        {
            min=s;
            jmin=i;
        }
    }
    cout<<min<<endl;
    //system("pause");
    return 0;
}