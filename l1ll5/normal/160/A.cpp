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
int n;
int a[N];
int main()
{
    n=read();
    int sum=0;
    for(int i=1;i<=n;i++)
        a[i]=read(),sum+=a[i];

        sort(a+1,a+n+1);
        int num=0;
        for(int i=n;i>=1;i--)
        {
            num+=a[i];
            if(num>sum-num)
            {
                printf("%d\n",n-i+1);
                break;
            }
        }


    return 0;
}