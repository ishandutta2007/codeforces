#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;
const int maxn=2e5+100;
int a[maxn];
int main()
{
    int n;
     
   scanf("%d",&n);
    for (int i=0;i<n;i++)
       scanf("%d",&a[i]);
    long long ans=0,cur=0;

    for (int i=0;i<n;i++)
    {
        long long ch=abs(a[i]-cur);
        if (a[i]>cur)
        {
            cur+=ch;
        }
        else
        {
            cur-=ch;
        }
        ans+=ch;
    }

  printf("%I64d",ans);
    return 0;
}