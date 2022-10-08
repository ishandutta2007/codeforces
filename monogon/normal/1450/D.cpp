#include <bits/stdc++.h>
using namespace std;

const int mxN = 300001;
int arr[mxN]; // input array
int cnt[mxN]; // cnt[x] = number of occurrences of x in the array
bool ans[mxN]; // the final answer
int n;

void solve() {
    cin>>n;
    for(int i = 0; i <= n; ++i) {
        cnt[i] = 0;
        ans[i] = 0;
    }
    for(int i = 0; i < n; ++i) {
        cin>>arr[i];
        arr[i]--; // switch to 0-indexing
        cnt[arr[i]]++;
    }
    int tp = -1;
    while(cnt[tp+1]==1) {
        tp++;
    }
    // each number from 0..n-1 has exactly one occurrence -> permutation
    ans[0] = tp==n-1;
    int l = 0; int r = n-1;
    
    // special case, min = 0
    ans[n-1] = cnt[0] > 0;
    
    // shrink the interval as long as our checks pass
    for(int i = n-1; i > 0; --i) {
        if(!ans[n-1]) break;
        ans[i] = true;
        int nxt = n-i-1;
        if(--cnt[nxt] == 0 && (arr[l]==nxt || arr[r]==nxt) && cnt[nxt+1]) {
            if(arr[l]==nxt)l++;
            if(arr[r]==nxt)r--;
            continue;
        }
        break;
    }
    
    for(int i = 0; i < n; ++i) {
        cout<<ans[i];
    }
    cout<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}