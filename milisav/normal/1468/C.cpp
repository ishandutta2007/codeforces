#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
bool srv[maxn];
queue<pair<int,int> > q;
priority_queue<pair<int,int> > pq;
int n;
int tp,m;
vector<int> ot;
int main() {
    scanf("%d",&n);
    int id=1;
    while(n--) {
        scanf("%d",&tp);
        if(tp==1) {
            scanf("%d",&m);
            q.push({m,-id});
            pq.push({m,-id});
            id++;
        }
        if(tp==2) {
            while(srv[-q.front().second]) q.pop();
            srv[-q.front().second]=true;
            ot.push_back(-q.front().second);
        }
        if(tp==3) {
            while(srv[-pq.top().second]) pq.pop();
            srv[-pq.top().second]=true;
            ot.push_back(-pq.top().second);
        }
    }
    for(auto id:ot) {
        printf("%d ",id);
    }
    return 0;
}