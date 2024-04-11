#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

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

#define maxn 100010
struct Point
{
    int pos,fire;
}   a[maxn];

bool cmp(Point a,Point b)
{
    return a.pos<b.pos;
}
int f[maxn][2];
int search(int l,int r,int t)
{
    if (t<a[1].pos) return 0;
    while (l<r)
    {
        int mid=(l+r)/2+(l+r)%2;
        if (a[mid].pos<=t)  l=mid;else r=mid-1;
    }
    return l;
}
int n;
int main()
{
    read(n);
    for (int i=1;i<=n;i++)  read(a[i].pos),read(a[i].fire);
    sort(a+1,a+n+1,cmp);
    f[1][1]=1;
    f[1][0]=0;
    for (int i=2;i<=n;i++)
    {
        int q=search(1,i-1,a[i].pos-a[i].fire-1);
        f[i][1]=f[q][1]+1;
        f[i][0]=max(f[i-1][0],f[i-1][1]);
    }
    printf("%d\n",n-max(f[n][0],f[n][1]));
    return 0;
}