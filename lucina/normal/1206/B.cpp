#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],z,m1,p1;
long long ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>=1){
            ans+=(a[i]-1);
        }
        else if(a[i]<=-1){
            ans+=(abs(a[i])-1);
            m1++;
        }
        else if(a[i]==0){
            ans++;
            z++;
        }
    }
    if(z>0){
        return !printf("%lld\n",ans);
    }
    if(z==0&&(m1%2==0)){
        return !printf("%lld\n",ans);
    }
    printf("%lld\n",ans+2);
}
/*
    Good Luck
        -Lucina
*/