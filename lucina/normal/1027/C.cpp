#include<stdio.h>
#include<algorithm>
using namespace std;

int a[1000005],n,t,x,b[500002],y;
int main(){
    scanf("%d",&n);
    for(int k=1;k<=n;k++){
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+t);
    int u=0;
    for(int i=0;i<t-1;i++){
        if(a[i]==a[i+1]){
            b[u]=a[i];
            u++,i++;
        }
    }
    x=b[0],y=b[1];
    for(int i=0;i<u-1;i++){
        if(x*b[i+1]<y*b[i]){
            x=b[i],y=b[i+1];
        }
    }
    printf("%d %d %d %d\n",x,x,y,y);
    }
    }