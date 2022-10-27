#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e6+10;
unordered_map<int,int> c;
int a[maxn],n,sum,b[maxn];
 main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
        c[a[i]]++;
    }
    int pt=0;
    for(int i=1;i<=n;i++){
        if(c[a[i]]){
        c[a[i]]--;
        if(c[(sum-a[i])/2]&&(sum-a[i])%2==0)
            b[++pt]=i;
        c[a[i]]++;
        }
    }
    printf("%lld\n",pt);
    for(int i=1;i<=pt;i++){
        printf("%lld ",b[i]);
    }
     
 }