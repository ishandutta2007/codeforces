#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=3e6+10;
int  n,a[maxn],sum,x,max1;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        sum+=x;
        max1=max(x,max1);
    }
    sum=(sum*2/n)+1;
    if(sum<max1)
        printf("%d\n",max1);
    else
        printf("%d\n",sum);
}