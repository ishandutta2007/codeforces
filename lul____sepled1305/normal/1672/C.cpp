#include <bits/stdc++.h>
using namespace std;
 
string ss[2] = {"NO","YES"};
 
int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ct = 0;
        for(int i=1;i<n;i++) {
            if(a[i] == a[i-1])
                ct++;
        }
        if(ct <= 1) {
            cout<<"0\n";
            continue;
        }
        int idx = -1;
        int dp[n], sp[n];
        for(int i=0;i<n;i++)
            dp[i] = 1e9, sp[i] = 1e9;
        for(int i=0;i<n;i++) {
            if(i == 0) {
                dp[i] = 0;
                continue;
            }
            if(a[i-1] == a[i] && idx == -1)
                idx = i;
            if(idx == -1)
                dp[i] = 0;
            else
                dp[i] = i-idx+1;
        }
        idx = -1;
        for(int i=n-1;i>=0;i--) {
            if(i == n-1) {
                sp[i] = 0;
                continue;
            }
            if(a[i] == a[i+1] && idx == -1)
                idx = i;
            if(idx == -1)
                sp[i] = 0;
            else
                sp[i] = idx-i+1;
        }
        int mini = 1e9;
        for(int i=0;i<n-1;i++) {
            if(i == 0) {
                mini = min(mini,1+sp[i+2]);
            }
            else if(i == n-2) {
                mini = min(mini,1+dp[i-1]);
            }
            else {
                mini = min(mini,1+dp[i-1]+sp[i+2]);
            }
        }
        cout<<mini<<'\n';
    }
    return 0;
}