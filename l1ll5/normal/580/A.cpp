#include <bits/stdc++.h>
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
int n,a[N],tmp,ans;
int main()
{
    n=read();
    for(int i=0;i<n;i++)a[i]=read();
    for(int i=1;i<n;i++)   if(a[i]>=a[i-1])tmp++,ans=ans>tmp?ans:tmp;else tmp=0;
    cout<<ans+1<<endl;

}