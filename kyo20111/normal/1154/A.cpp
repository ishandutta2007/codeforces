#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[5],chk;
int main(){
    for(int i=0;i<4;i++) scanf("%lld",&arr[i]);
    for(int i=0;i<4;i++) chk+=arr[i];
    chk/=3;

    for(int i=0;i<4;i++) if(chk != arr[i]) printf("%lld ",chk-arr[i]);
}