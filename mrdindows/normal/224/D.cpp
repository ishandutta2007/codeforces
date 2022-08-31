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

int main()
{
    string s,t;
    cin>>s>>t;
    int n=0,k=0;
    int *a=new int[s.length()];
    int *b=new int[s.length()];
    set<int> v[40];
    for (;n<s.length();n++)
    {
        if (k<t.length() && s[n]==t[k])
        {
            k++;
        }
        a[n]=k-1;
    }
    for (int i=0;i<t.length();i++)
    {
        v[t[i]-'a'].insert(i);
    }
    if (k<t.length())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    k--;
    for (int i=n-1;i>=0;i--)
    {
        if (k>=0 && s[i]==t[k])
        {
            k--;
        }
        b[i]=k+1;
    }
    if (k>=0 || b[n-1]==t.length())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        int t=s[i]-'a';
        set<int>::iterator j=v[t].lower_bound(a[i]+1);
        if (j==v[t].begin())
        {
                cout<<"NO"<<endl;
                return 0;
        }
        else
        {
            int r=*(--j);
            if (r<b[i])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    
    return 0;
}