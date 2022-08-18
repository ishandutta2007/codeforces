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
//const unsigned long long mod=(long long)1000000*1000000+7;
#define mod1 1000000009
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


class   FoxAndMountain
{
public: 
    bool a[10][10];
    char n;
    long long kat[55];
    int count(int n, string history)
    {
        kat[0]=0;
        int h=history.size();
        for (int i=1;i<30;i++)
        {
            ll sum=0;
            for (int j=0;j<i;j++)
            {
    //          sum=(sum+kat[j]*kat[i-j-1])%mod;
            }
        //  kat[i]=mod;
        }
        if (n%2) return 0;
        int max=n/2;
        int k=0;
        for (int i=0;i<history.size();i++)
            if (history[i]=='U')
                k++;
            else
                k--;
        ll res=0;
        if (k==0)
        {
            for (int i=0;i+h<=n;i+=2)
                res=(res+kat[i]*kat[n-i-h]);
        }
        else
            if (k<0)
            {

            }

            return 0;
    }
    char go(char *color,char num)
    {
        char max=num;
        for (int i=0;i<n;i++)
        {
            if (color[i]==0)
            {
                int cur=num+1;
                char *newc=new char[10];
                for (int j=0;j<n;j++)
                    newc[j]=color[j];
                newc[i]=1;
                bool e=true;
                vector<bool> used(n,0);
                dfs(used,i,cur,newc);
                cur=go(newc,cur);
                if (cur>max)
                    max=cur;
            }
        }
        return max;
    }
    void dfs(vector<bool> &used,int v,int &cur,char *newc)
    {
        for (int i=0;i<n;i++)
        {
            if (!used[i] && a[v][i])
            {
                used[i]=true;
                if (newc[i]==1)
                    cur--,newc[i]=2;
                if (newc[i]==0)
                {
                    newc[i]=2;
                    dfs(used,i,cur,newc);
                }
            }
        }
    }
};

int powmod(int a, int n, int mod)

{

    int res(1);
    while (n)
    {
        if (n&1)
            res=(res*a)%mod;
        a=(a*1ll*a)%mod;
        n>>=1;
    }
    return res;
}
int sumcifr(ll x)
{
    int s=0;
    while (x>0)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}

int main()
{
    ll n;
    cin>>n;
    ll minres=1111111111;
    for (int s=1;s<=170;s++)
    {
        ll d=(ll)s*s+4*n;
        if ((ll)(sqrt(d))*(ll)(sqrt(d))==d)
        {
            ll t=sqrt(d)+0.0000001;
            ll x=(-s+t);
            ll x1=x/2;
            if (x%2==0 && sumcifr(x/2)==s && x/2<minres && x>0 && x1*x1+s*x1-n==0)
            {
                minres=x/2;
            }
        }
        else
        {
            continue;
        }
    }
    if (minres==1111111111)
    {
        cout<<-1<<endl;
    }
    else
        cout<<minres<<endl;
    return 0;

}