#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,st,qs[105],mi;
char s[105];

int main(){
    mi=0;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        qs[i]=qs[i-1]+(s[i]=='+'?1:-1);
        mi=min(mi,qs[i]);
    }
    if(mi==0){
        printf("%d",qs[n]);
    }
    else{
        printf("%d",qs[n]-mi);
    }
}