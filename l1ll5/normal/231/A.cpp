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
int n,ans;
int a[N];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int x=0;
        x+=read(),x+=read(),x+=read();
        if(x>1)ans++;
    }

    cout<<ans<<endl;
}