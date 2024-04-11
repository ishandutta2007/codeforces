#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
priority_queue<pair<long long,long long> > pq;
long long n,k;
long long a[maxn];
long long ci[maxn];
long long val(long long x,long long c) {
    long long p=x/c;
    long long q=x%c;
    return (c-q)*p*p+q*(p+1)*(p+1);
}
long long dif(long long i) {
    return val(a[i],ci[i])-val(a[i],ci[i]+1);
}
int main() {
    scanf("%lld %lld",&n,&k);
    for(long long i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        ci[i]=1;
        pq.push({dif(i),i});
    }
    for(long long i=n;i<k;i++) {
        pair<long long,long long> pp=pq.top();
        pq.pop();
        long long u=pp.second;
        ci[u]++;
        pq.push({dif(u),u});
    }
    long long ans=0;
    for(long long i=0;i<n;i++) ans+=val(a[i],ci[i]);
    printf("%lld",ans);
    return 0;
}