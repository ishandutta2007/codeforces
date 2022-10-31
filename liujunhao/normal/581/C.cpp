#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100000
int n,a[MAXN+10],ans,k,b[MAXN+10];
int main()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans+=a[i]/10;
        if(a[i]%10){
            b[i]=10-a[i]%10;
            a[i]+=b[i];
        }
    }
    sort(b+1,b+n+1);
    for(i=1;!b[i]&&i<=n;i++);
    for(;i<=n;i++)
        if(k>=b[i])
            k-=b[i],ans++;
        else
            break;
    if(i>n)
        for(i=1;i<=n;i++){
            ans+=min(k/10,(100-a[i])/10);
            k-=10*min(k/10,(100-a[i])/10);
            if(k<10)
                break;
        }
    printf("%d\n",ans);
}