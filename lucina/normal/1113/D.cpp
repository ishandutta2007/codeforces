#include<bits/stdc++.h>
using namespace std;
bool ch;
int n;
char s[5010],a,r[5010];
int main(){
    scanf("%s",s);
    n=strlen(s);
    a=s[0];
    ch=true;
    for(int i=0;i<n/2;i++){
        if(s[i]==a&&s[n-i-1]==a){
            continue;
        }
        else
            ch=false;
    }
    if(ch){
        printf("Impossible");
        return 0;
    }
    ch=true;
    bool fuck;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=i+1+n;j++){
            r[j-i-1]=s[j%n];
        }
        fuck=true;
        for(int j=0;j<n/2;j++){
            if(r[j]==r[n-j-1])
                continue;
            else
                fuck=false;
        }
        if(fuck){
            for(int j=0;j<n;j++){
                if(s[j]!=r[j]){
                    fuck=false;
                }
            }
            if(!fuck){
                printf("1\n");
                return 0;
            }
        }
    }
    printf("2\n");
}