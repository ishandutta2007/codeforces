#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Maxm = 10005;

int n;
int a[Maxn], b[Maxn];
bool taken[Maxn];
vector <int> res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
       cin >> a[i] >> b[i];
       if (a[i] > b[i]) swap(a[i], b[i]);
    }
    while (true) {
          int ends = Maxm;
          for (int i = 0; i < n; i++) 
             if (!taken[i]) ends = min(ends, b[i]);
          if (ends == Maxm) break;
          res.push_back(ends);
          for (int i = 0; i < n; i++)
             taken[i] = taken[i] || a[i] <= ends && ends <= b[i];
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i + 1 < res.size()) cout << " ";
        else cout << endl;
    }
    return 0;
}