#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        priority_queue<int> pq;
        for(int i=1;i<=n;i++)
            pq.push(-i);
        int a[n];
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        if(n == 1) {
            cout<<"-1\n";
            continue;
        }
        for(int i=0;i<n-2;i++) {
            int cur = -pq.top();
            pq.pop();
            if(cur != a[i]) {
                cout<<cur<<' ';
                continue;
            }
            int nw = -pq.top();
            pq.pop();
            pq.push(-cur);
            cout<<nw<<' ';
        }
        int r1 = -pq.top(); pq.pop();
        int r2 = -pq.top(); pq.pop();
        if(r1 == a[n-2] || r2 == a[n-1])
            swap(r1,r2);
        cout<<r1<<' '<<r2<<endl;
    }
    return 0;
}