#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n;  string s;
   cin >> n >> s;
   int n0 = 0;
   int n1 = 0;
   for (char c : s) {
      n0 += c == 'z';
      n1 += c == 'n';
   }
   while (n1--) {
      cout << "1 ";
   }
   while (n0--) {
      cout << "0 ";
   }
}