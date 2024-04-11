#include<bits/stdc++.h>
using namespace std;
char s[300];
int a[7],k,p;
int main(){
    scanf("%s",s+1);
    int n=0;
    for(int i=1;s[i]!='\0';i++)
    n++;
    for(int i=1;i<=5;i++){
        if(double(n)/double(i)<=double(20)){
        if(n%i){
            k=i-n%i;
        }
        n+=k;
        p=1;
        printf("%d %d\n",i,n/i);
        for(int j=1;j<=i;j++){
            for(int t=1;t<=n/i;t++){
            if(k!=0&&t==n/i)
                printf("*"),k--;
            else
                printf("%c",s[p]),p++;
            }
            printf("\n");
        }
        return 0;
    }
    }
}