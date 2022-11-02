#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n];
        long long sum = 0;
        for(int i=0;i<n;i++) cin>>a[i], sum += a[i];
        sort(a,a+n,greater<int>());
        priority_queue<long long> pq; pq.push(sum);
        int pt = 0;
        int ct = 0;
        while(pq.size() != 0) {
            long long cur = pq.top();
            pq.pop();
            //cout<<cur<<' '<<st.count(cur)<<endl;
            ct++;
            if(ct > 2*n) break;
            if(pt == n) break;
            if(cur == a[pt]) {
                pt++;
                continue;
            }
            if(cur == 1)
                break;
            pq.push(cur/2);
            pq.push((cur+1)/2);
        }
        if(pt == n && pq.empty()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}