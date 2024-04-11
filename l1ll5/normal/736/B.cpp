#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
bool ck(int x)
{
    for(int i=2;i*i<=x;i++)
    if(x%i==0)return 0;
    return 1;
}
int main()
{
    n=read();
    if(n==2)
    {
        puts("1");
    }
    else
    {
        if(n%2==0)
        puts("2");
        else
        {
            if(ck(n))puts("1");
            else if(ck(n-2))puts("2");
            else puts("3");
        }
    }
}