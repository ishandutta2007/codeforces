#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, a;
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--) {
      vector<int> pref;
      cin >> n;
      for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a == 1) {
          pref.push_back(a);
        } else {
          while (a - 1 != pref.back()) {
            pref.pop_back();
          }
          ++pref.back();
        }
        string cpref = "";
        for (auto i: pref) {
          cout << cpref << i;
          cpref = ".";
        }
        cout << '\n';
      }
    }
    return 0;
}