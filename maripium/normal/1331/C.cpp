#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int A;
   cin >> A;
   int B = 0;
   B += (A >> 5 & 1) << 5;
   B += (A >> 4 & 1) << 0;
   B += (A >> 3 & 1) << 2;
   B += (A >> 2 & 1) << 3;
   B += (A >> 1 & 1) << 1;
   B += (A >> 0 & 1) << 4;
   cout << B;
}