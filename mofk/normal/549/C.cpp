#include <bits/stdc++.h>

using namespace std;

int N, K, odd, even, x;

int main(void) {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (x & 1) ++odd; else ++even;
    }
    if (N == K) return cout << ((odd & 1) ? "Stannis" : "Daenerys") << endl, 0;
    if ((N - K) % 2 == 0) {
        int numTurns = (N - K) / 2;
        if (even <= numTurns && K % 2 == 1) cout << "Stannis" << endl;
        else cout << "Daenerys" << endl;
    }
    else {
        int numTurns = (N - K) / 2;
        if (odd <= numTurns || (even <= numTurns && K % 2 == 0)) cout << "Daenerys" << endl;
        else cout << "Stannis" << endl;
    }
}