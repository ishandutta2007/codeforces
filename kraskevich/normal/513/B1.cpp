#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long num;
    cin >> num;
    num--;
    vector<int> res(n);
    int l = 0;
    int r = n - 1;
    for (int i = n - 2; i >= 0; i--) {
	if (num & (1ll << i))
	    res[r--] = n - 2 - i;
	else
	    res[l++] = n - 2 - i;
    }
    res[l++] = n - 1;
    for (int x : res)
	cout << x + 1 << " ";
    return 0;
}