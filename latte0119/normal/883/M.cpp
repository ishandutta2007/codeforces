#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 X1, Y1, X2, Y2;
  cin >> X1 >> Y1 >> X2 >> Y2;

  int64 ret = 0;
  ret += abs(X1 - X2) * 2;
  ret += abs(Y1 - Y2) * 2;
  ret += 4;
  if(X1 == X2 || Y1 == Y2) ret += 2;

  cout << ret << endl;
}