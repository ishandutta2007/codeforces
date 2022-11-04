#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4],d;
int main(){
    for(int i=1;i<=3;i++) scanf("%lld",&a[i]);
    scanf("%lld",&d);
    sort(a+1,a+4);
    printf("%lld",max(0ll,d-(a[2]-a[1]))+max(0ll,d-(a[3]-a[2])));
}