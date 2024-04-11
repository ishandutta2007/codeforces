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
#define fill(m,v) memset(m,v,sizeof(m))
//#define flush {cout.flush();fflush(stdout);}
#define random(x) (((rand()<<15)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
//#define long long long
#include<map>
#include<set>
using namespace std;
#define mod 1000000007
typedef long long lli;
int l;
string s;
int maxl=0;
string maxs="";
void add(int n,string a)
{
    if (n==l)
    {
        if (maxs<a)
        {
            bool e=true;
            int c=a.length();
            for (int i=0;i<(c+1)/2;i++)
                if (a[i]!=a[c-i-1])
                    e=false;
            if (e)          maxs=a;
        }
    }
    else
    {
        string s1=a;
        add(n+1,s1);
        string s2=a;
        s2+=s[n];
        add(n+1,s2);
    }
}
int main()
{  
    cin>>s;
    l=s.length();
    add(0,"");
    cout<<maxs;
    return 0;
}