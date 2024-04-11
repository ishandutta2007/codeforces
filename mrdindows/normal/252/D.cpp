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
#define random(x) (((rand()*25)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 qstupid_cmath_make_me_cry
#define tm stupid_ctime
#define pb push_back
#define mp make_pair
#include<map>
#include<set>
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

int main()
{
    int n,k;
    cin>>n>>k;
    int t=-1;
    int p=-1;
    int *a=new int[n];
    int *s=new int[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",s+i);
    }
    int *b=new int[n];
    int *r=new int[n];
    for (int i=0;i<n;i++)
        b[i]=i+1;
    bool e=true;
    for (int j=0;j<n;j++)
    {
        if (s[j]!=b[j])
        {
            e=false;
            break;
        }
    }
    if (e)
    {
        cout<<"NO\n";
        return 0;
    }
    for (int i=0;i<k;i++)
    {
        for (int j=0;j<n;j++)
        {
            r[a[j]-1]=b[j];
        }
        swap(b,r);

//      for (int i=0;i<n;i++)
//          cout<<b[i]<<" ";
//      cout<<endl;

        bool e=true;
        for (int j=0;j<n;j++)
        {
            if (s[j]!=b[j])
            {
                e=false;
                break;
            }
        }
        if (e)
        {
            t=i+1;
            break;
        }
    }
    bool z=false;
        if (t==1)
        {
            z=true;
        }
    if (t%2==k%2 && t>0 && !z)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    for (int i=0;i<n;i++)
        b[i]=i+1;
    for (int i=0;i<n;i++)
    {
        r[a[i]-1]=i+1;
    }
    swap(a,r);
    for (int i=0;i<k;i++)
    {
        for (int j=0;j<n;j++)
        {
            r[a[j]-1]=b[j];
        }
        swap(b,r);
        bool e=true;

        for (int j=0;j<n;j++)
        {
            if (s[j]!=b[j])
            {
                e=false;
                break;
            }
        }
        if (e)
        {
            p=i+1;
            break;
        }
    }
    if (t==1 && p==1 && k>1)
    {
        cout<<"NO\n";
        return 0;
    }
    else
    {
        if (t==1 && k%2==1)
        {
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    if (p%2==k%2 && p>0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}