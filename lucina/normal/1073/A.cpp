#include<stdio.h>
char s[2000];
int n;
int main(){
    scanf("%d",&n);
    scanf("%s",&s);
    bool check=true;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            printf("YES\n%c%c\n",s[i],s[i+1]);
            check=false;
            break;
    }
    }
    if(check)
        printf("NO\n");


}