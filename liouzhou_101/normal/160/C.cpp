#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long n;
long long k;
int a[100010];

int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    a[0]=-2000000000;
    a[n+1]=2000000000;
    long long now=0;
    for (int i=1;i<=n;++i)
    {
        if (a[i]==a[i-1]) continue;
        long long num=1;
        int j=i;
        while (a[j+1]==a[j])
        {
            ++j;
            ++num;
        }
        if (now+n*num>=k)
        {
            for (int j=1;j<=n;++j)
            {
                now+=num;
                if (now>=k)
                {
                    printf("%d %d\n",a[i],a[j]);
                    return 0;
                }
            }
        }
        now+=(n*num);
    }
    return 0;
}