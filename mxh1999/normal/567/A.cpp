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
const int maxn=100010;
int n;
int a[maxn],hzh[maxn],hhw[maxn];

int main()
{
    read(n);
    for (int i=1;i<=n;i++)  read(a[i]);
    hzh[n]=a[n]-a[n-1],hhw[n]=a[n]-a[1];
    hzh[1]=a[2]-a[1],hhw[1]=a[n]-a[1];
    for (int i=2;i<=n-1;i++)
    {
        hzh[i]=min(a[i]-a[i-1],a[i+1]-a[i]);
        hhw[i]=max(a[i]-a[1],a[n]-a[i]);
    }
    for (int i=1;i<=n;i++)  printf("%d %d\n",hzh[i],hhw[i]);
    return 0;
}