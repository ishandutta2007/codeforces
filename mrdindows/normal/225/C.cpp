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
//const unsigned long long mod=(long long)1000000*1000000+7;
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 using namespace std;

typedef long long lli;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
const int INF=500000000;
int mas[1001][2];
int main()
{

    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int *a=new int[1000];
    for (int i=0;i<m;i++)
        a[i]=0;
    char c;
    for (int i=0;i<n;i++)
    {
        
        for (int j=0;j<m;j++)
        {
            cin>>c;
            if (c=='#') a[j]++;
        }
    }
    int **b=new int*[m];
    for (int i=0;i<m;i++)
    {
        b[i]=new int[m];
        for (int j=0;j<m;j++)
        {
            b[i][j]=-1;
        }
    }
    for (int i=0;i<m+1-x;i++)
    {
        int sum=0;
        for (int j=0;j<x-1;j++)
        {
            sum+=a[i+j];
        }
        for (int j=x-1;j<y && j+i<m;j++)
        {
            sum+=a[i+j];
            b[i][i+j]=sum;
        }
    }
    for (int i=1;i<x;i++)
        mas[i][0]=mas[i][1]=INF;
    mas[0][0]=mas[0][1]=0;
    for (int i=x;i<=m;i++)
    {
        for (int c=0;c<=1;c++)
        {
            int min=INF;
            for (int j=x;j<=y && i-j>=0;j++)
            {
                if (c==0)
                {
                    if (min>mas[i-j][1]+b[i-j][i-1]) min=mas[i-j][1]+b[i-j][i-1];
                }
                else
                {
                    if (min>mas[i-j][0]+n*j-b[i-j][i-1]) min=mas[i-j][0]+n*j-b[i-j][i-1];
                }
            }
            mas[i][c]=min;
        }
    }
    cout<<min(mas[m][0],mas[m][1])<<endl;
    return 0;
}