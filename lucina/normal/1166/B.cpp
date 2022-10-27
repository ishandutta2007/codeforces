#include<bits/stdc++.h>
using namespace std;
int k,r,c;
char s[5]={'a','e','i','o','u'};

int main(){
    scanf("%d",&k);
    r=-1;
    for(int i=5;i<k;i++){
        if(k%i==0){
            if(k/i>=5){
                r=i;
                break;
            }
        }
    }
    if(r==-1)return printf("-1"),0;
    c=k/r;
    for(int i=0;i<5;i++){
        for(int j=0;j<c;j++){
            printf("%c",(j<5)?s[(j+i)%5]:s[i]);
        }
    }
    for(int i=5;i<r;i++){
        for(int j=0;j<c;j++)
            printf("%c",s[j%5]);
    }
}