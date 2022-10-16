#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, K;

int main(void) {
    cin >> N >> K;
    if (K == 1) { ff(i, 1, N) cout << i << " "; cout << endl; return 0; }
    ff(i, K + 1, N) cout << i << " ";
    for (int i = 1; i + i <= K; ++i) cout << i << " " << K + 1 - i << " ";
    if (K & 1) cout << (K + 1) / 2; cout << endl;
    return 0;
}