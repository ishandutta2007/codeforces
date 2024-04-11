#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    for (; c >= 0; c -= b) if (c % a == 0) return cout << "Yes" << endl, 0;
    cout << "No" << endl;
    return 0;
}