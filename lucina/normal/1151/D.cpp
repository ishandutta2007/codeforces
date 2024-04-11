#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
struct pa{
int a,b;
bool operator<(const pa x)const{
    return a-b>x.a-x.b;
}
}s[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&s[i].a,&s[i].b);
    }
    sort(s+1,s+1+n);
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=((1ll*(i-1)*(s[i].a))+(1ll*(n-i)*(s[i].b)));
    }
    printf("%lld\n",sum);

}