#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> s[10000];
int n;
vector<long long> v;
int d[200000];
int main() {
    long long a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&a);
        s[i]={a,0};
    }
    long long t=0;
    for(int i=0;i<n;i++) {
        scanf("%lld",&b);
        t+=b;
        s[i]={s[i].first,b};
    }
    sort(s,s+n);
    t=0;
    for(int i=n-2;i>=0;i--) {
        if(s[i].first==s[i+1].first) {
            t+=(1-d[i+1])*s[i+1].second;
            t+=(1-d[i])*s[i].second;
            d[i+1]=d[i]=1;
            v.push_back(s[i].first);
        }
        for(auto j:v) {
            if((s[i].first&j)==s[i].first) {
                v.push_back(s[i].first);
                t+=(1-d[i])*s[i].second;
                d[i]=1;
                break;
            }
        }
    }
    printf("%lld",t);
    return 0;
}