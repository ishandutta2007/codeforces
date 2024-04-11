#include<bits/stdc++.h>
#define maxn 2000000
using namespace std;
long long n;
long long a[maxn];
vector<long long> ts;
bool sl[maxn];
mt19937 rng(time(0));
clock_t beg;
double ela() {
    clock_t cur = clock();
    return 1.00*(cur - beg) / CLOCKS_PER_SEC;
}
vector<long long> facts;
int main() {
    beg = clock();
    scanf("%lld",&n);
    for(long long i=2;i<=1000000ll;i++) {
        if(!sl[i]) {
            ts.push_back(i);
            for(long long j=i*i;j<=1000000ll;j+=i) sl[j]=true;
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        ans=ans+(a[i]&1ll);
    }
    int ab=1;
    while(ela() < 0.2) {
        int i=rng()%n;
        for(int j=-ab;j<=ab;j++) {
            long long ct=a[i]+j;
            if(ct<=0) continue;
            facts.clear();
            for(int k=0;k<ts.size() && ts[k]*ts[k]<=ct;k++) {
                if(ct%ts[k]==0) {
                    facts.push_back(ts[k]);
                    while(ct%ts[k]==0) ct/=ts[k];
                }
            }
            if(ct!=1) facts.push_back(ct);
            for(auto t:facts) {
                long long cur=0;
                for(int j=0;j<n;j++) {
                    if(a[j]<t) cur+=(t-a[j]);
                    else {
                        cur+=min(a[j]%t,t-a[j]%t);
                    }
                }
                ans=min(ans,cur);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}