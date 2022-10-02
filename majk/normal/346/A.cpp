#include <iostream>

using namespace std;
int gcd(int a, int b) {
    if (a > b) { swap(a,b); }
    return a?gcd(b%a,a):b;
}

int main() {
    int N; cin >> N;
    int G, M;
    cin >> G;
    M = G;
    for (int i = 1; i < N; ++i) {
        int x; cin >> x;
        G = gcd(G, x);
        M = max(M, x);
    }
    cout << ((M/G-N)%2 ? "Alice" : "Bob") << endl;
}