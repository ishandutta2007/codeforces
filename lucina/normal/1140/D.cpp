#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;

int main(){
    scanf("%d",&n);
    for(int i=2;i<=n-1;i++){
        ans+=(i*(i+1));
    }
    printf("%lld\n",ans);
}