#include<bits/stdc++.h>
using namespace std;

int n, A[100005];

bool case1() {
    for (int i=1; i<=n; i++) if (A[i] != 1) return 0;
    return 1;
}

void runpg() {
    cin>>n;
    for (int i=1; i<=n; i++) cin>>A[i];
    if (case1()) {
        if (n%2==0) cout<<"Second\n";
        else cout<<"First\n";
    } else {
        int cnt = 0;
        for (int i=1; i<=n; i++, cnt++) if (A[i] != 1) break;
        if (cnt%2==0) cout<<"First\n";
        else cout<<"Second\n";
    }
}

main() {
    int t;
    cin>>t;
    while (t--) {
        runpg();
    }
}