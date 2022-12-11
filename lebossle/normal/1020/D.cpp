#include <bits/stdc++.h>
using namespace std;

int n;
int dif(int x) {
  cout << "? " << x << endl;
  cout << "? " << (x>n/2 ? x-n/2 : x+n/2) << endl;
  int a, b;
  cin >> a >> b;
  return a-b;
}

int main() {
  cin >> n;
  if ((n/2)%2==1) {
    cout << "! -1" << endl;
    return 0;
  }
  int l=1, ldif=dif(1);
  int r=n/2+1, rdif=-ldif;
  if (ldif == 0) {
    cout << "! " << l << endl;
    return 0;
  }
  while (true) {
    int m=(l+r)/2, mdif=dif(m);
    if (mdif == 0) {
      cout << "! " << m << endl;
      return 0;
    }
    if (mdif/abs(mdif) == ldif/abs(ldif)) {
      l = m;
      ldif = mdif;
    } else {
      r = m;
      rdif = mdif;
    }
  }
}