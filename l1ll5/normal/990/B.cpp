#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k,a[N],ans;
bool b[N];
set<int> S;
set<int>::iterator it;
int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    a[0]=-100;
    for(int i=1;i<=n;i++)
    if(a[i]!=a[i-1])
    {
        int j=i-1;
        while(j&&a[i]<=a[j]+k)
        {
            if(b[j])break ;
            b[j]=1;
            j--;
        }
    }
    for(int i=1;i<=n;i++)
    if(!b[i])ans++;
    cout<<ans<<endl;
}