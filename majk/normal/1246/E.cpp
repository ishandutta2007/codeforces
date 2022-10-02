#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
#define x first
#define y second

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N); 
    for (int&a: A) cin >> a;

    vector<bitset<2001>> G(1<<N);
    G[0][0] = true;
    for (int i = 0; i < (1<<N); i++) {
        for (int j = 2000/K; j > 0; --j) {
            if (G[i][j*K]) {
                G[i][j] = true;
            }
        }

        for (int j = 0; j < N; j++) {
            if (i&1<<j) continue;
            G[i|1<<j] |= G[i] << A[j];
        }
    }

    if (G.back()[1]) {
        cout << "YES\n";
        int mask = (1<<N)-1;
        int sum = 1;
        int mul = 0;
        vector<pii> W;
        while (mask) {
            bool found = false;
            for (int i = 0; i < N; ++i) {
                if (mask&1<<i && A[i] <= sum && G[mask^1<<i][sum-A[i]]) {
                    W.push_back({mul,A[i]});
                    mask ^= 1<<i;
                    found = true;
                    sum -= A[i];
                    break;
                }
            }
            if (!found) {
                mul++;
                sum *= K;
            }
        }
        while (W.size() > 1) {
            sort(W.begin(),W.end());
            pii a = W[W.size()-1];
            pii b = W[W.size()-2];
            W.resize(W.size()-2);
            cout << a.y << ' ' << b.y << endl;
            int s = a.y+b.y;
            int t = a.x;
            while (s%K == 0) { s /= K; t--; }
            W.push_back({t,s});
        }
    } else {
        cout << "NO\n";
    }
}