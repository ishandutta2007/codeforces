#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> Primes{2,3,5,7,11,13,17,19};
int P = Primes.size();

void genAll(int i, int q, int c, int up, vector<int>& s) {
    if (q == i) {
        s.push_back(c);
        return;
    }

    while (c <= up) {
        genAll(i+1, q, c, up, s);
        c *= Primes[i];
    }
}

void genSimple(int i, int q, int c, vector<int>& s) {
    if (q == i) {
        s.push_back(c);
        return;
    }

    genSimple(i+1, q, c, s);
    genSimple(i+1, q, c * Primes[i], s);
}

set<int> generate(int K) {
    for (int i = 0; i <= P; ++i) {
        for (int j = i; j <= P; ++i) {
            int tot = 1;
            for (int k = 0; k < j; ++k) tot *= Primes[k];
            vector<int> S,T;
            set<int> Q;
            if (2*K*K < tot) continue;
            genAll(0, i, 1, 2*K*K/tot, S);
            genSimple(0, j, 1, T);
            sort(T.begin(),T.end());
            reverse(T.begin(),T.end());
            for (int t:T) for (int s:S) {
                if (Q.size() < K) Q.insert(s*t);
            }
            if (Q.size() >= K) return Q;
        }
    }
}

int main() {
    int K; cin >> K;
    auto G = generate(K);
    for (int g:G) cout << g << ' ';
    cout << endl;
    //for (int K = 10; K <= 5000; ++K) {
    //    if (!generate(K)) cout << K << endl;
    //}
}