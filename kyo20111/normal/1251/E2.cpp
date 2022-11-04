#include<bits/stdc++.h>
using namespace std;
int t,n,c[202020];
pair<int,int> p[202020];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d %d",&p[i].first, &p[i].second);
        sort(p+1, p+1+n);
 
        for(int i=0;i<n;i++) c[i] = 0;
        for(int i=1;i<=n;i++) c[p[i].first]++;
        priority_queue<int> pq;
 
        int m = 0,cur = 1;
        long long ans = 0;
 
        for(int i=0;i<n;i++){
            while(cur<=n && p[cur].first == i){
                pq.push(p[cur].second);
                cur++;
            }
            
            if(!pq.empty()) pq.pop();
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        printf("%lld\n",ans);
    }
}