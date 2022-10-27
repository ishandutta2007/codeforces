#include<stdio.h>
int n,g,i,h;
char a[1000],v;
void rever(char *x,int t){
    for(int j=0;j<=(t-1)/2-(t%2);j++){
        v=x[j];
        x[j]=x[t-1-j];
        x[t-1-j]=v;
    }
}
//  abcdefghi ihgfedcba
int main(){
scanf("%d",&n);
scanf("%s",a);
for(int i=2;i<=n;i++){
    if(n%i==0)
        rever(a,i);
}

printf("%s",a);
}