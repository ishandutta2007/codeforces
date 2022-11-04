#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,arr[101010],ans,chk[101010];
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<n;i++) pq.push(arr[i+1]-arr[i]);
    for(int i=1;i<=n-k;i++){
        ans+=pq.top();
        pq.pop();
    }
    printf("%d",ans+k);
}