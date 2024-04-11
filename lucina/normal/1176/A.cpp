#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long n;
int a,b,c,t;

int main(){
    scanf("%d",&t);
    while(t--){
    scanf("%lld",&n);
    a=0,b=0,c=0;
    while(n%2==0){
        a++;n/=2;
    }
    while(n%3==0){
        b++;n/=3;
    }
    while(n%5==0){
        c++;n/=5;
    }
    if(n>1){printf("-1\n");
    continue;
    }
       printf("%d\n",a+2*b+3*c);

    }
}