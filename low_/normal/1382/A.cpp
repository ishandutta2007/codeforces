#include<bits/stdc++.h>
using namespace std;

int n, m;
int A[1005], B[1005];

void runpg() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>A[i];
    for (int i=1; i<=m; i++) cin>>B[i];
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        if (A[i] == B[j]) {
            cout<<"YES\n";
            cout<<"1 "<<A[i]<<"\n";
            return;
        }
    }
    cout<<"NO\n";
    
}

main() {
    int t;
    cin>>t;
    while (t--) {
        runpg();
    }
}