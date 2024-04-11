#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,a[maxn],y,t,g,f[maxn],k,fuck;
int p[]={4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
int convert(int x){
    if(f[x])
        return f[x];
    fuck=x;
    g=1,y=0;
    while(x!=0){
        y+=((x+1)%2)*g;
        x=x/2;
        g*=2;
    }
    f[fuck]=y,f[y]=fuck;
    return y;
}

int main(){
    scanf("%d",&n);
    g=n,t=0;
    while(g!=0){
        t++;
        g/=2;
    }
    if(n%2)
    printf("NO\n");
    else{
        printf("YES\n");
        for(int i=n;i>=1;i--)
            convert(i);
        for(int i=1;i<=n;i++)
            printf("%d ",f[i]);
        printf("\n");
    }
    if(n<=5){
        printf("NO\n");
        return 0;
    }
    if(n==6){
        printf("YES\n");
        printf("3 6 2 5 1 4");
        return 0;
    }
    if(n>=7){
        k=0;
     while(n>p[k]){
        k++;
        if(n==p[k]){
        printf("NO\n");
        return 0;
        }
     }
        printf("YES\n5 3 2 6 7 4 1 ");
        if(n==7)
        return 0;
    for(int i=1;i<k-1;i++){
        for(int j=p[i];j<p[i+1];j++){
            if(j==p[i])
                printf("%d ",p[i+1]-1);
            else
                printf("%d ",j-1);
        }
        }
        for(int j=p[k-1];j<=n;j++){
            if(j==p[k-1])
                printf("%d ",n);
            else
                printf("%d ",j-1);
    }
    }}