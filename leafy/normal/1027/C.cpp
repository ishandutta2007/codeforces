#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t;
int n;
int a[1000005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        double la=0; double mn=(double)0x3f3f3f3f;int i=1,p1,p2;
        while(i<n)
        {
            if(a[i]==a[i+1])
            {
                if(la!=0) 
                {
                    double k=4.0*(a[i]+la)*(a[i]+la)/(a[i]*la);
                    if(k<mn)
                    {
                        mn=k;p1=la,p2=a[i];
                    }
                }
                la=a[i];
                i++;
            }
            i++;
        }
        printf("%d %d %d %d\n",p1,p1,p2,p2);
    }
    return 0;
}