#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int A, B, C, D;
   cin >> A >> B >> C >> D;
   if (A == B + 1 && C + D == 0) {
      cout << "YES\n";
      while (B--) {
         cout << "0 1 ";
      }
      cout << "0\n";
      return 0;
   }
   if (D == C + 1 && A + B == 0) {
      cout << "YES\n";
      while (C--) {
         cout << "3 2 ";
      }
      cout << "3\n";
   return 0;
   }
   if (A > B || D > C) {
      cout << "NO\n";
      return 0;
   }
   int X = B - A;
   int Y = C - D;
   if (abs(X - Y) > 1) {
      cout << "NO\n";
      return 0;
   }
   vector<int> norm;
   for (int z = 0; z < min(X, Y); ++z) {
      norm.emplace_back(1);
      norm.emplace_back(2);
   }
   if (X > Y) {
      norm.emplace_back(1);
   } else if (X < Y) {
      norm.insert(norm.begin(), 2);
   }
   cout << "YES\n";
   for (int z : norm) {
      cout << z << " ";
      if (z == 1) {
         --B;
         while (A && B) {
            cout << "0 1 ";
            --A;
            --B;
         }
      } else {
         --C;
         while (C && D) {
            cout << "3 2 ";
            --C;
            --D;
         }
      }
   }
   if (A && B && C && D) {
      assert(norm.empty());
      while (A && B) {
         cout << "0 1 ";
         --A;
         --B;
      }
      while (C && D) {
         cout << "2 3 ";
         --C;
         --D;
      }
   } else {
      while (A && B) {
         cout << "1 0 ";
         --A;
         --B;
      }
      while (C && D) {
         cout << "2 3 ";
         --C;
         --D;
      }
   }
}