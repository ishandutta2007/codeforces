#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a,b,c,d,h,x,y;
char s[10];

int main(){
    scanf("%s",s);
    a=(s[0]-'0')*10+(s[1]-'0');
    c=(s[3]-'0')*10+(s[4]-'0');
    scanf("%s",s);
    b=(s[0]-'0')*10+(s[1]-'0');
    d=(s[3]-'0')*10+(s[4]-'0');
    h+=(a+b)*60+c+d;
    h/=2;
    if(h/60<10)printf("0");
    printf("%d:",h/60);
    if(h%60<10)printf("0");
    printf("%d",h%60);

}