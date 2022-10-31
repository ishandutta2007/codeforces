#include <iostream>
#define MAXN 100000
using namespace std;
int k,n,a[MAXN+10],sum[MAXN+10],tot;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    if(sum[n]%k)
        puts("No");
    else{
        int i,t=sum[n]/k,cnt=0;
        for(i=1;i<=n;i++)
            if(sum[i]%t==0)
                cnt++;
        if(cnt!=k)
            puts("No");
        else{
            puts("Yes");
            int la=0;
            for(int i=1;i<=n;i++)
                if(sum[i]%t==0)
                    printf("%d ",i-la),la=i;
        }
    }
}