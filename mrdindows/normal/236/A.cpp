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
#include<map>
#include<set>
#include<queue>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#pragma comment(linker,"/STACK:256000000")
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<int, bool> pib;

#define maxll 0x7fffffffffffffffLL
#define mod 1000000009

#pragma comment(linker,"/STACK:256000000")
 
/*int *primes=new int[10000];
int prcount=0;
void prepare()
{
        int N=100000;
        int *u=new int[N];
        memset(u,0,N*4);
        for (int i=2;i<N;i++)
        {
                if (u[i]==0)
                {
                        primes[prcount++]=i;
                        u[i]=i;
                }
                for (int j=0;j<prcount && i*primes[j]<N && primes[j]<=u[i];j++)
                        u[i*primes[j]]=primes[j];
        }
        delete[]u;
}*/
int main()
{
    ll n,k,x,b,c,d;
    double r,t,u;
    string s;
    cin>>s;
    set<int> a;
    for (int i=0;i<s.size();i++)
        a.insert(s[i]);
    if (a.size()%2)
    {
        cout<<"IGNORE HIM!"<<endl;
    }
    else
    {
        cout<<"CHAT WITH HER!"<<endl;
    }
    return 0;
}