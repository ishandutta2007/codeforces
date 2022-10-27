#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=2e5+10;
int n,a[maxn];
map<int,int> fuck;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        fuck[a[i]]=i;
    }
    long long ans=1;
    int pt=fuck[a[1]];
    int i;
    for(i=1;i<=n;i++){
        if(i>pt){
            ans*=2;
            ans%=mod;
        }
        pt=max(pt,fuck[a[i]]);
    }
    printf("%lld\n",ans);
}