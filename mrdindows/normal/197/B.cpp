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
#define flush {cout.flush();fflush(stdout);}
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
int nod(int a,int b)
{
    while (a!=0 && b!=0)
        if (a>b) a%=b;
        else b%=a;
    return a+b;
}
int main()
{ 
    /*  fstream f("in.txt");*/
    int n,m;
    cin>>n>>m;
    int *a=new int[n+1];
    int *b=new int[m+1];
    for (int i=0;i<n+1;i++)
        cin>>a[i];
    for (int i=0;i<m+1;i++)
        cin>>b[i];
    if (n>m)
    {
        if (a[0]*b[0]<0) cout<<"-";
        cout<<"Infinity";
    }
    else
    if (n<m)
        cout<<"0/1";
    else
    {
        int c=nod(abs(a[0]),abs(b[0]));
        if (a[0]*b[0]<0) cout<<"-";
        cout<<abs(a[0])/c<<"/"<<abs(b[0])/c;
    }
    return 0;
}