#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;

int main(void) {
    cin >> N;
    bool fl = 0; int a;
    ff(i, 1, N) {
        int z = 0;
        ff(j, 1, N) { cin >> a; z = max(z, a); }
        if (z < N - 1) cout << z << " ";
        else { cout << z + fl << " "; fl = 1; }
    }
    return 0;
}