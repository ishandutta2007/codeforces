#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int ans,n,m,p,q;

int main(){
    scanf("%d%d",&n,&m);
    if(n>m||m%n){
        printf("-1");
        return 0;
    }
int    x=m/n;
    while(x%2==0){
        p++;x>>=1;
    }
    while(x%3==0){
        q++;x/=3;
    }
    if(x>1){
        printf("-1");
    }
    else
        printf("%d",p+q);
}