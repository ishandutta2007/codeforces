#include<stdio.h>
using namespace std;
int n,m,i,j,k,LO,counn;
int a[800001];
int b[800001];
int h[800001];
void hope(int j){
    h[m]=1;
    h[0]=j;
    for(k=j;k<=n;k++)
    {
        if(a[k]+b[n-h[k]+j+1]>LO & k!=m)
        {
            h[0]=0;
            break;
        }
    }
    if(h[0]==0)
        hope(j+1);
    else
        printf("%ld",j);
}
int main(){
    scanf("%ld %ld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%ld",&a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%ld",&b[i]);
    }
    for(i=1;i<=n;i++){
        h[i]=1;
    }
    LO=a[m]+b[1];
    for(k=1;k<=n;k++)
    {
        if(k<m)
        {
            h[k]=k+1;
        }
        else
        {
            h[k]=k;
        }
    }
    hope(1);
    return 0;
}