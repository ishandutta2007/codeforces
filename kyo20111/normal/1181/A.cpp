#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
int main(){
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld ",(a+b)/c);
    if(a/c + b/c == (a+b)/c) printf("0");
    else printf("%lld",min(c-a%c,c-b%c));
}