#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char s[2000];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    if(n%2){
        printf("%c",s[n/2+1]);
        for(int i=n/2;i>0;i--)
            printf("%c%c",s[n-i+1],s[i]);
    }
    else{
        for(int i=n/2;i>0;i--)
            printf("%c%c",s[i],s[n-i+1]);
    }

}