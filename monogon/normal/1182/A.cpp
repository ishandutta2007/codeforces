
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;

int main() {
    cin >> n;
    cout << (n % 2 ? 0 : 1 << (n / 2)) << endl;
}