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


/*

int main()
{
    int n,x;
    cin>>n>>x;
    int *a=new int[n];
    int *b=new int[n];
}**/

int main()
{
    int n,m;
    cin>>n>>m;
    const int N = 10000000;
    int *lp=new int[N+1];
    int *aq=new int[100000];
    int *bq=new int[100000];
    for (int i=0;i<N+1;i++)
        lp[i]=0;
    int *pr=new int[1511000];
    int w=0;
    for (int i=2; i<=N; ++i) 
    {
        if (lp[i] == 0) 
        {
            lp[i] = i;
            pr[w++]=i;
        }
        for (int j=0; j<w && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    int *ac=new int[10000000];
    int *bc=new int[10000000];
    int e;
    for (int i=0;i<w;i++)
    {
        ac[pr[i]]=bc[pr[i]]=0;
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",&(e));
        aq[i]=e;
        while (e>1)
        {
            int t=lp[e];
            e/=t;
            ac[t]++;
        }
    }
    for (int i=0;i<m;i++)
    {
        scanf("%d",&(e));
        bq[i]=e;
        while (e>1)
            {
                int t=lp[e];
                e/=t;
                if (ac[t]>0) ac[t]--;
                else  bc[t]++;
            }
    }
    cout<<n<<" "<<m<<'\n';
    for (int i=0;i<n;i++)
    {
        e=1;
        while (aq[i]>1)
            {
                int t=lp[aq[i]];
                aq[i]/=t;
                if (ac[t]>0) { ac[t]--; e*=t;}
            }
        printf("%d ",e);
    }
    cout<<'\n';
    for (int i=0;i<m;i++)
    {
        e=1;
        while (bq[i]>1)
            {
                int t=lp[bq[i]];
                bq[i]/=t;
                if (bc[t]>0) { bc[t]--; e*=t;}
            }
        printf("%d ",e);
    }
    
    cout<<'\n';
    return 0;
}