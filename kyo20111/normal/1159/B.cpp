#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[300300], ans = 1e9, chk[300300];
priority_queue<pair<int,int>> pq;
int main(){
    scanf("%d",&n);
    int l = 1, r = n;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) pq.push({-a[i], i});
    while(!pq.empty()){
        int id = pq.top().second; pq.pop();
        chk[id] = 1;
        while(l <= r && chk[l]) l++;
        while(l <= r && chk[r]) r--;
        if(l <= r) ans = min({ans, a[id]/abs(id - l), a[id]/abs(id - r)});
    }
    printf("%d",ans);
}