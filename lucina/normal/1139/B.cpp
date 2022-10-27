#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],x;
long long ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int s=a[n];
    ans+=s;
    for(int i=n-1;i>=1;i--){
        x=min(s-1,a[i]);
        x=max(x,0);
        s=x;
        ans+=s;
    }
    printf("%lld\n",ans);
}