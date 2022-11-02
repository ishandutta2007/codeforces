#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        int a[n],b[n],ra[n],rb[n];
        bool visit[n];
        for(int i=0;i<n;i++) {
            cin>>a[i];
            a[i]--;
            ra[a[i]] = i;
            visit[i] = false;
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
            b[i]--;
            rb[b[i]] = i;
        }
        int ans = 1;
        for(int i=0;i<n;i++) {
            if(!visit[a[i]]) {
                visit[a[i]] = true;
                int runner = i;
                while(visit[b[runner]] != true) {
                    visit[b[runner]] = true;
                    runner = ra[b[runner]];
                }
                ans *= 2;
                ans %= mod;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}