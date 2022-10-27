#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=2e5;
int x[maxn],y[maxn],a,b,g,sum,l,r,sum1;
int main(){
    scanf("%d%d",&a,&b);
     sum=0,l=0;
     g=a+b;
    for(int i=1;i+sum<=g;i++){
        l++,x[l]=i;
        sum+=i;
    }
    r=0;
    sum1=0;
    for(int i=l;sum>a;i--){
        if(sum1+x[i]<=b){
            r++,y[r]=x[i];
            sum-=x[i];
            sum1+=y[r];
            x[i]=0;
        }
    }
    printf("%d\n",l-r);
    for(int i=1;i<=l;i++){
        if(x[i]!=0)
        printf("%d ",x[i]);
        }
    printf("\n%d\n",r);
    for(int i=1;i<=r;i++)
        printf("%d ",y[i]);
    printf("\n");
}