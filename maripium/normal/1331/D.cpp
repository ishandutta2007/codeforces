#include <bits/stdc++.h>

using namespace std;

int main() {
   string S;
   cin >> S;
   cout << ((S.back() - '0') & 1);
}