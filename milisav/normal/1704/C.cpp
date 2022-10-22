#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int t;
int n,m;
int a[maxn];
priority_queue<int> pq;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++) {
            scanf("%d",&a[i]);
        }
        sort(a,a+m);
        a[m]=a[0]+n;
        for(int i=1;i<=m;i++) {
            pq.push(a[i]-a[i-1]-1);
        }
        int ct=0;
        int ans=0;
        while(!pq.empty()) {
            int x=pq.top();
            pq.pop();
            if(x<=ct) continue;
            if(x-ct<=2) {
                ans++;
                ct+=2;
                continue;
            }
            ans+=(x-ct-1);
            ct+=4;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}