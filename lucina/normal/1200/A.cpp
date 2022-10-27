#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
char s,b[10];

int main(){
    for(int i=0;i<10;i++)
        b[i]='0';
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c",&s);
        if(s=='L'){
            for(int j=0;j<=9;j++){
                if(b[j]=='0'){
                    b[j]='1';
                    break;
                }
            }
        }
        else if(s=='R'){
            for(int j=9;j>=0;j--){
                if(b[j]=='0'){
                    b[j]='1';
                    break;
                }
            }
        }
        else{
            b[s-'0']='0';
        }
    }
    for(int i=0;i<10;i++){
        printf("%c",b[i]);
    }
}
/*
    Good Luck
        -Lucina
*/