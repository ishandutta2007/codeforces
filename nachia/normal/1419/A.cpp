#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop() {
    int N; string S; cin >> N >> S;
    if (N % 2 == 0) {
        bool ok = false;
        rep(i, N / 2) {
            int d = S[i * 2 + 1] - '0';
            if (d % 2 == 0) ok = true;
        }
        printf(ok ? "2\n" : "1\n");
    }
    else {
        bool ok = false;
        rep(i, (N + 1) / 2) {
            int d = S[i * 2] - '0';
            if (d % 2 == 1) ok = true;
        }
        printf(ok ? "1\n" : "2\n");
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) loop();
    return 0;
}