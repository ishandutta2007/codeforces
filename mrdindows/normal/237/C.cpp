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
#define mod 1073741824//1000000009

#pragma comment(linker,"/STACK:256000000")
 
int *primes=new int[100000];
int prcount=0;
int *u;
int N=1000001;
void prepare()
{
        
        u=new int[N];
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
}
ll nod(ll a,ll b)
{
    while (a)
    {
        b%=a;
        ll t=b;
        b=a;
        a=t;
    }
    return b;
}
ll nok(ll a,ll b)
{
    return a/nod(a,b)*b;
}


int main() 
{
    prepare();
    int a,b,k;
    cin>>a>>b>>k;
   if (b+1-a<k)
  {
 cout<<-1<<endl; 
 return 0; 
  }   
    int *mas=new int[b+1];
    mas[0]=mas[a-1]=0;
    for (int i=a;i<=b;i++)
    {
        mas[i]=mas[i-1];
        if (i==u[i])
        {
            mas[i]++;
        }
    }
    int l=k,r=b-a+1;
    while (l!=r)
    {
        int m=(l+r)/2;
        bool e=true;
        for (int i=a+m-1;i<=b;i++)
        {
            if (mas[i]-mas[i-m]<k)
            {
                e=false;
                break;
            }
        }
        if (e)
        {
            r=m;
        }
        else
        {
            l=m+1;
        }
    }
    bool e=true;
    for (int i=a+r-1;i<=b;i++)
    {
        if (mas[i]-mas[i-r]<k)
        {
            e=false;
            break;
        }
    }
    if (!e)
        cout<<-1<<endl;
    else
        cout<<r<<endl;
    return 0;
}

/*
int main() 
{
    int n;
    cin>>n;
    int *a=new int[n];
    int *d=new int[n];
    int *amax=new int[n];
    int *amin=new int[n];
    CL(d);
    for (int i=0;i<n;i++)
        scanf("%d",a+i);
    CP(amax,a);
    CP(amin,a);
    for (int i=2;i<=n;i++)
    {
        for (int j=i-1;j<n;j++)
        {
            if (d[j]==d[j-1] && (a[j]==a[max] || ))
        }
    }
    cout<<endl;


    system("pause");
    return 0;
}*/