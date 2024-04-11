#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long p=0,t=0;
    for(int i=n;i>=1;i--){
        p+=(a[i]/2);
        if(a[i]&1&&p>0){
            p--;t++;
        }
    }
    t+=(p*2)/3;
    printf("%lld\n",t);
}
/*
    Lucina
*/