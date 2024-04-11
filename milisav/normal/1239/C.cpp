#include<bits/stdc++.h>
using namespace std;
int n;
int p;
long long t[200000];
long long a[200000];
long long mq=0;
priority_queue<int> wnt;
priority_queue<int> pq;
priority_queue<pair<long long,pair<int,int> > > events;
int main() {
    scanf("%d %d",&n,&p);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&t[i]);
        events.push({-t[i],{0,-i}});
        a[i]=-1;
    }
    long long tp=n+1;
    while(!events.empty()) {
        long long ct=events.top().first;
        if(events.top().second.first==0) wnt.push(events.top().second.second);
        else {
            a[-events.top().second.second]=-events.top().first;
            while(!pq.empty() && a[-pq.top()]!=-1) pq.pop();
        }
        events.pop();
        if(events.empty() || events.top().first!=ct) {
            if(pq.size()>0) tp=-pq.top();
            else tp=n+1;
            if(wnt.size()>0 && -wnt.top()<=tp) {
                events.push({-(max(mq,t[-wnt.top()])+p),{1,wnt.top()}});
                pq.push(wnt.top());
                mq=(max(mq,t[-wnt.top()])+p);
                wnt.pop();
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%lld ",a[i]);
    return 0;
}