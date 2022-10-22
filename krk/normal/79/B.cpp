#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, t;
vector <int> wst;

int main()
{
    int a, b;
    cin >> n >> m >> k >> t;
    while (k--) {
          cin >> a >> b;
          wst.push_back((a-1)*m + b-1);
    }
    sort(wst.begin(), wst.end());
    while (t--) {
          cin >> a >> b;
          int cur = (a-1)*m + b-1;
          int i;
          for (i = 0; i < wst.size() && wst[i] < cur; i++) ;
          if (i < wst.size() && wst[i] == cur) cout << "Waste\n";
          else {
               int ans = (cur - i) % 3;
               if (ans == 0) cout << "Carrots\n";
               else if (ans == 1) cout << "Kiwis\n";
               else cout << "Grapes\n";
          }
    }
    return 0;
}