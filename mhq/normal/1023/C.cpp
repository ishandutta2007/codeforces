#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, k;
string s;
const int maxN = 2 * (int)1e5 + 10;
bool used[maxN];
int main() {
    ios_base::sync_with_stdio(false);
   //freopen("input.txt", "r", stdin);
   cin >> n >> k;
   cin >> s;
   int bal = 0;
   for (int i = 0; i < k; i++) {
       if (s[i] == '(') bal++;
       else bal--;

   }
   int need = bal / 2;
   for (int i = k - 1; i >= 0; i--) {
       if (bal == 0) continue;
       if (s[i] == '(') {
           used[i] = true;
           bal -= 2;
       }
   }
   for (int i = 0; i < k; i++) {
       if (!used[i]) cout << s[i];
   }
   for (int i = 0; i < need; i++) cout << ')';
   return 0;
}