#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int cnt,num;
    ll cost;
    bool operator < (const node &a)const{
        if(cost==a.cost) return cnt>a.cnt;
        return cost>a.cost;
    }
};
int n,m;
ll sv[101010];
node food[101010];
priority_queue<node> pq;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&food[i].cnt);
    for(int i=1;i<=n;i++) scanf("%lld",&food[i].cost);
    for(int i=1;i<=n;i++) food[i].num=i;
    for(int i=1;i<=n;i++) pq.push(food[i]);
    for(int k=1;k<=m;k++){
        int a,b;
        ll re=0;
        scanf("%d %d",&a,&b);
        if(food[a].cnt){
            if(b>food[a].cnt){
                b-=food[a].cnt;
                re+=food[a].cost*food[a].cnt;
                food[a].cnt=0;
            }else{
                food[a].cnt-=b;
                re+=food[a].cost*b;
                b=0;
            }
        }
        while(b>0 && !pq.empty()){
            int nw=pq.top().num;
            if(food[nw].cnt == 0){
                pq.pop();
                continue;
            }
            if(b>food[nw].cnt){
                b-=food[nw].cnt;
                re+=food[nw].cost*food[nw].cnt;
                food[nw].cnt=0;
            }else{
                food[nw].cnt-=b;
                re+=food[nw].cost*b;
                b=0;
            }
        }
        if(b) printf("0\n");
        else printf("%lld\n",re);
    }
}