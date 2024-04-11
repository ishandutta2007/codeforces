#include<bits/stdc++.h>
using namespace std;
int n,t;
char s[52];

int main(){
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
    t+=(s[i]=='a');
    printf("%d\n",t>n/2?n:t*2-1);
}