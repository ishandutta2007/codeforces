#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
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
int n,m;
vector<int> v;
int main()
{
    //freopen("data.in","w",stdout);
    n=read(),m=read();
    if(n==1 && m==0)
    {
        puts("1");
        return 0;
    }
    int t=1;
    while(t*(t+1)<=m) t++;
    t--;
    int tmp=m-t*(t+1);
    t++;

    for(int i=1;i<=t*2;i++)
    v.push_back(i);

    if(tmp!=0)
    {
        if(tmp<t)
        {
            int cur=t-tmp;
            v.push_back(t*2+1+2*cur);
        }
        else
        {
            v.push_back(t*2+1);
            tmp-=t;
            int cur=t-tmp;

            v.push_back(t*2+2+2*cur);
        }
    }

    int sz=v.size();
    if(sz>n)
    {
        puts("-1");
        return 0;
    }

    int cc=n-sz;
    for(int i=1;i<=cc;i++)
    {
        v.push_back(1000000000-(cc-i)*10000);
    }

    //printf("%d\n",n);
    for(int i=0;i<n;i++)printf("%d ",v[i]);

}