#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,a,b,c;
char s[maxn];
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    bool check=true;
    for(int i=0;s[i+1]!='\0';i++){
        if(s[i+1]<s[i]){
                check=false;
                a=i;
                break;
        }
    }
    if(check){
        for(int i=0;i<n-1;i++)
            printf("%c",s[i]);
        return 0;
    }
    for(int i=0;s[i]!='\0';i++){
        if(i!=a)
            printf("%c",s[i]);
    }
}