#include<bits/stdc++.h>
using namespace std;
int n;
int a[200];
unordered_set<long long> s;
long long mod=1000000000007;
void add() {
    for(int i=0;i<(1<<15);i++) {
        long long d=1;
        long long p=100007;
        long long h=0;
        for(int j=0;j<n;j++) {
            h=(h+d*__builtin_popcount(((1<<30)-(1<<15))&((i<<15)^a[j])))%mod;
            d=(d*p)%mod;
        }
        s.insert(h);
    }
}
pair<long long,int> find2() {
    for(int t=0;t<=30;t++) {
        long long dq=1;
        long long pq=100007;
        long long fh=0;
        for(int j=0;j<n;j++) {
            fh=(fh+dq*t)%mod;
            dq=(dq*pq)%mod;
        }
        for(int i=0;i<(1<<15);i++) {
            long long d=1;
            long long p=100007;
            long long h=0;
            for(int j=0;j<n;j++) {
                h=(h+d*__builtin_popcount(((1<<15)-1)&(i^a[j])))%mod;
                d=(d*p)%mod;
            }
            long long dif=(fh-h+mod)%mod;
            if(s.find(dif)!=s.end()) {
                return {dif,i};
            }
        }
    }
    return {-1,-1};
}
int find1(long long ht) {
    for(int i=0;i<(1<<15);i++) {
        long long d=1;
        long long p=100007;
        long long h=0;
        for(int j=0;j<n;j++) {
            h=(h+d*__builtin_popcount(((1<<30)-(1<<15))&((i<<15)^a[j])))%mod;
            d=(d*p)%mod;
        }
        if(h==ht) return i<<15;
    }
    return 0;
}
int find() {
    pair<long long,int> t=find2();
    if(t.second==-1) return -1;
    return find1(t.first)|t.second;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    add();
    int x=find();
    printf("%d",x);
    //for(int i=0;i<n;i++) printf("%d\n",__builtin_popcount(a[i]^x));
    return 0;
}