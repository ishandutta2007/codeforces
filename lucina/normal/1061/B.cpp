#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long n,m,a[maxn],b[maxn];
long long sum=0;

int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if(n==1){
        printf("%d ",0);
        return 0;
    }
    long long res=0,fuck=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        res++;
        if(a[i]>fuck)
            fuck++;
    }
    res+=a[n]-fuck;
    printf("%lld",sum-res);
}