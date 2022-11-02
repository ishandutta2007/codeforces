# include <iostream>
# include <cstdio>
using namespace std;

int F(int x)
{
    int ret=0;
    while(x>0)
    {
        x=x & (x-1);
        ret++;
    }
    return ret;
}

long long a[100];

int n,x;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        a[F(x)]++;
    }
    long long ans=0;
    for(int i=0;i<64;i++)
        if(a[i]>0)
            ans+=a[i]*(a[i]-1)>>1;
    cout<<ans<<endl;
}