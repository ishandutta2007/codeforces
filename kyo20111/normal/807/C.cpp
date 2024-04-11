#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        ll a,b,c,d; scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(c == d){
            printf("%d\n",(a==b?0:-1));
            continue;
        }
        if(!c){
            printf("%d\n",(!a?0:-1));
            continue;
        }

        ll e = max({(a/c)+(a%c?1:0),(b/d)+(b%d?1:0),((b-a)/(d-c))+((b-a)%(d-c)?1:0)});
        c*=e, d*=e;
        printf("%lld\n",d-b);
    }
}