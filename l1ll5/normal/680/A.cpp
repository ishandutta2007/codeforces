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
int a[N];
int n=5;
int buc[N],ans,sum;
int main()
{
    for(int i=1;i<=n;i++)a[i]=read(),ans+=a[i];
    sum=ans;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        buc[a[i]]++;
        if(buc[a[i]]>1&&buc[a[i]]<4)
        {
            ans=min(ans,sum-a[i]*buc[a[i]]);
        }
    }
    cout<<ans<<endl;
}