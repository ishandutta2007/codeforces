#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],x[maxn],d[maxn],ans,b[maxn];

int main(){
    scanf("%d",&n);
    int u=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        d[i]=a[i]-a[i-1];
        }
    for(int i=1;i<=n;i++){
            bool check=true;
        for(int j=0;j<i;j++){
            x[j]=d[j+1];
        }
        for(int k=1;k<=n;k++){
            if(d[k]!=x[(k-1)%i]){
            check=false;
            break;}
        }
        if(check){
            b[u]=i;u++;
        }
    }
    printf("%d\n",u-1);
    for(int i=1;i<u;i++)
            printf("%d ",b[i]);
}