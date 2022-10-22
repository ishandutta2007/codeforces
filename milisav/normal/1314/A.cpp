#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n;
int a[maxn];
int t[maxn];
pair<int,int> c[maxn];
long long tot=0;
priority_queue<int> pq;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int j=0;j<n;j++) {
        scanf("%d",&t[j]);
        c[j]={a[j],t[j]};
    }
    sort(c,c+n);
    long long ans=0;
    for(int i=0;i<n;i++) {
        pq.push(c[i].second);
        tot+=c[i].second;
        while(i+1<n && c[i+1].first==c[i].first) {
            i++;
            pq.push(c[i].second);
            tot+=c[i].second;
        }
        long long cur=c[i].first;
        while(!pq.empty() && (i+1==n || cur!=c[i+1].first)) {
            tot-=pq.top();
            pq.pop();
            ans+=tot;
            cur++;
        }
    }
    printf("%lld",ans);
    return 0;
}