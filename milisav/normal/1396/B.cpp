#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 200
using namespace std;
priority_queue<pair<int,int> > pq;
int a[maxn];
int n;
int t;
int main() {
    scanf("%d",&t);
    while(t--) {
        while(!pq.empty()) pq.pop();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            pq.push({a[i],-2});
        }
        int id=0;
        while(true) {
            if(pq.size()==0) break;
            pair<int,int> ct=pq.top();
            if(id-ct.second==1) {
                pq.pop();
                if(pq.size()==0) break;
                pair<int,int> rt=pq.top();
                pq.pop();
                pq.push(ct);
                rt.first--;
                rt.second=id;
                if(rt.first) pq.push(rt);
            }
            else {
                pq.pop();
                ct.first--;
                ct.second=id;
                if(ct.first) pq.push(ct);
            }
            id++;
        }
        if(id&1) printf("T\n");
        else printf("HL\n");
    }
	return 0;
}