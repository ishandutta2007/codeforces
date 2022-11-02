#include <bits/stdc++.h>
using namespace std;

int main() {
int t, s, q;
cin >> t >> s >> q;
int cnt = 0;
while (s < t) cnt++, s *= q;
cout << cnt;
}