#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n;
int b[maxn];
map<int,long long> m;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    long long ans=0;
    for(int i=0;i<n;i++) {
        m[b[i]-i]+=b[i];
        ans=max(ans,m[b[i]-i]);
    }
    printf("%lld",ans);
}