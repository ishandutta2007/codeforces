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
const int INF=500000000;
int a[50][50];
int b[50][50];
int main()
{
    int na,ma,nb,mb;
    cin>>na>>ma;
    char c;
    for (int i=0;i<na;i++)
        for (int j=0;j<ma;j++)
        {
            cin>>c;
            a[i][j]=c-48;;
        }
    cin>>nb>>mb;
    for (int i=0;i<nb;i++)
        for (int j=0;j<mb;j++)
        {
            cin>>c; b[i][j]=c-48;
        }
    int maxsum=-INF;
    int maxx;
    int maxy;
    for (int x=-max(na,nb)+1;x<max(nb,na);x++)
        for (int y=-max(mb,ma)+1;y<max(mb,ma);y++)
        {
            int sum=0;
            for (int i=max(0,-x);i+x<nb && i<na;i++)
            {
                for (int j=max(0,-y);j+y<mb && j<ma;j++)
                    sum+=a[i][j]*b[i+x][j+y];
            }
            if (sum>maxsum)
                maxsum=sum,maxx=x,maxy=y;
        }
        cout<<maxx<<" "<<maxy<<"\n";
        //system("pause");
    return 0;
}