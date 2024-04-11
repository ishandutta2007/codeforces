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
    fb(i, 20, 0) if (N >> i & 1) cout << i+1 << " ";
    return 0;
}