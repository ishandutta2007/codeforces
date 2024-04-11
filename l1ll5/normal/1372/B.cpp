#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int t;
int n,m;
int a[N];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int solve(int x)
{
    int mx=0;
    for(int i=1;i*i<=x;i++)
    if(x%i==0)
    {
        if(i!=x)
        mx=max(mx,i);
        if(x/i!=x)
        mx=max(mx,x/i);
    }
    return mx;
}
int main()
{
    t=read();
    while(t--){
        n=read();
        int x=solve(n);


            printf("%d %d\n",x,n-x);

    }
}