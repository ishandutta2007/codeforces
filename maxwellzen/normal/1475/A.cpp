#include<bits/stdc++.h>

using namespace std;

int main() {
int t; cin >> t;
while (t--) {long long n; cin >> n; cout << (__builtin_popcountll(n)==1 ? "NO\n":"YES\n");}
}