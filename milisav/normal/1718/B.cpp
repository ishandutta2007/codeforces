#include<bits/stdc++.h>
#define maxn 102
using namespace std;
int t;
int k;
long long c[maxn];
long long fib[maxn];
long long sm[maxn];
priority_queue<long long> pq;
int main() {
    fib[0]=fib[1]=1;
    sm[0]=1;
    sm[1]=2;
    for(int i=2;i<maxn;i++) {
        fib[i]=fib[i-1]+fib[i-2];
        sm[i]=fib[i]+sm[i-1];
    }
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&k);
        long long csum=0;
        while(!pq.empty()) pq.pop();
        for(int i=1;i<=k;i++) {
            scanf("%lld",&c[i]);
            csum+=c[i];
            pq.push(c[i]);
        }
        int fs=0;
        while(sm[fs]<csum) fs++;
        if(sm[fs]>csum) {
            printf("NO\n");
            continue;
        }
        if(k==1) {
            if(fs==0) printf("YES\n");
            else printf("NO\n");
            continue;
        }
        long long to_add=-1;
        bool ok=true;
        while(!pq.empty()) {
            long long tp=pq.top();
            pq.pop();
            if(tp<fib[fs]) {
                ok=false;
                break;
            }
            tp-=fib[fs];
            fs--;
            if(fs<0) break;
            if(to_add>=0) pq.push(to_add);
            to_add=tp;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}