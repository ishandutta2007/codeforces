#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    if (n1 > n2)
	cout << "First";
    else
	cout << "Second";
    return 0;
}