//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 100010
typedef long long ll;
int n,m;
int ss,hzw,hzw2,tt;
int a[maxn],hzh[maxn],hzh1[maxn];
ll ans;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        hzh[a[i]]++;
    }
    for (int i=1;i<=n;i++)
    {
        ss+=hzh[i]&1;
        tt+=(hzh[i]&1)*i;
    }
    if (ss>1)
    {
        printf("0\n");
        return 0;
    }
    for (hzw=1;hzw*2<=n && a[hzw]==a[n-hzw+1];hzw++);
    if (hzw*2>n)
    {
        cout<<1LL*n*(n+1)/2<<endl;
        return 0;
    }
    hzw--;
    for (hzw2=(n+1)>>1;hzw2>=1 && a[hzw2]==a[n-hzw2+1];hzw2--);
    hzw2++;
    int tmp=1,tmp2=n;
    while (tmp<=n/2 && (++hzh1[a[tmp]])*2<=hzh[a[tmp]]) tmp++;
    memset(hzh1,0,sizeof(hzh1));
    tmp--;
    while (tmp2>(n+1)/2 && (++hzh1[a[tmp2]])*2<=hzh[a[tmp2]])   tmp2--;
    tmp2++;
    ans=1LL*(hzw+1)*(hzw+1);
    if (tmp>=n/2 && (a[(n+1)>>1]==tt || !tt))           ans+=1LL*(n-hzw2+1-hzw)*(hzw+1);else ans+=1LL*(tmp-hzw)*(hzw+1);
    if (tmp2<=(n+1)/2+1 && (a[(n+1)>>1]==tt || !tt))    ans+=1LL*(n-hzw2+1-hzw)*(hzw+1);else ans+=1LL*(n-tmp2+1-hzw)*(hzw+1);
    cout<<ans<<endl;
    return 0;
}