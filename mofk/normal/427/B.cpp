#include<stdio.h>
int main(void)
{
    long int n,j,i,t,k=0,c,a[200005],b[200005],ans=0;
    int ok=0,nook=0;
    scanf("%ld%ld%ld",&n,&t,&c);
    for(i=1;i<=n;i++) {
        scanf("%ld",&a[i]);
        if(a[i]>t){
            k++;b[k]=i;ok=1;
        }
        else nook=1;
    }
    b[0]=0;
    b[k+1]=n+1;
    if(ok==1&&nook==1){
        for(j=1;j<=k+1;j++) if(b[j]-b[j-1]>c) ans+=b[j]-b[j-1]-c;
        printf("%ld",ans);
    }
    else if(nook==0) printf("0");
    else printf("%ld",n-c+1);
}