#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<memory.h>
#include<algorithm>
#include<string>
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
typedef long long LL;
/*
int mod_exp(LL a,LL b)
{
 LL res=1;
 while(b){
 if(b&1) res=res*a%mod;
 a=a*a%mod;
 b>>=1;
 }
 return res;
}*/
int main()
{ 
    int n;
    cin>>n;
    if (n==0)
        cout<<"0 0 0";
    else
    if (n==1)
        cout<<"0 0 1";
    else
        if (n==2)
            cout<<"0 1 1";
        else
            if (n==3) 
                cout<<"1 1 1";
            else
        {
            
    int a=0,b=1,c=1;
    while (c<=n)
    {
        int t=b;
        c=b+c;
        b=a+b;
        a=t;
        if (b+c==n)
            cout<<a<<" "<<b<<" "<<b;
    }
        }
    return 0;
}