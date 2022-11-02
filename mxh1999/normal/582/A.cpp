#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

#define maxn 510
int num[maxn*maxn];
int sum[maxn*maxn];
int a[maxn*maxn];
int n,m,cnt;
int b[maxn];
int gcd(int a,int b)
{
    if (a<b)    swap(a,b);
    if (b==0)   return a;
    return gcd(b,a%b);
}
int main()
{
    read(n);
    for (int i=1;i<=n*n;i++)    read(a[i]),num[i]=a[i];
    sort(num+1,num+n*n+1);
    cnt=unique(num+1,num+n*n+1)-(num+1);
    for (int i=1;i<=n*n;i++)
    {
        int qqq=lower_bound(num+1,num+cnt+1,a[i])-num;
        sum[qqq]++;
    }
    int pos=cnt;
    for (int i=1;i<=n;i++)
    {
        while (sum[pos]<=0) pos--;
        b[i]=num[pos];
        sum[pos]--;
        for (int j=1;j<i;j++)
        {
            int gg=gcd(b[i],b[j]);
            int qqq=lower_bound(num+1,num+cnt+1,gg)-num;
            sum[qqq]-=2;
        }
    }
    for (int i=1;i<=n;i++)  printf("%d ",b[i]);
    return 0;
}