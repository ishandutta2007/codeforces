#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char s[maxn];

int main(){
    scanf("%s",s);
    int n=strlen(s);
    for(int l=1;l<=n/2;l++){
        int pt=l;
        for(int i=l,k=0;i<n;i++){
            k=(s[i]==s[i-l])?k+1:0;
            if(k==l)pt-=l,k=0;
            s[pt++]=s[i];
        }
        n=pt;
    }
    s[n]=0;
    printf("%s",s);
}