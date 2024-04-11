#include <bits/stdc++.h>

using namespace std;

int main() {
   long long n; cin >> n;
   long long d = 1, num = 9;
   while (true) {
      if (num * d >= n) break;
      n -= num * d;
      d++;
      num *= 10;
   }
   long long cur = 1;
   for (int i = 0; i < d - 1; ++i) cur *= 10;
   cur += (n - 1) / d;
   n -= (n - 1) / d * d;
   deque<int> dq;
   while (cur) {
      dq.push_front(cur % 10);
      cur /= 10;
   }
   cout << dq[n - 1] << '\n';
}