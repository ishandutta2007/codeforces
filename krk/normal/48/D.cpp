#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

const int Maxn = 100001;

int n;
list <int> freq[Maxn];
int res[Maxn];
int cnt;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        freq[tmp].push_back(i);
    }
    while (!freq[1].empty()) {
          cnt++;
          for (int i = 1; !freq[i].empty(); i++) {
              res[freq[i].back()] = cnt;
              freq[i].pop_back();
          }
    }
    int i;
    for (i = 0; i < n; i++)
        if (!res[i]) break;
    if (i < n) cout << "-1\n";
    else {
         cout << cnt << endl;
         for (i = 0; i < n; i++) {
             cout << res[i];
             if (i + 1 < n) cout << " ";
             else cout << endl;
         }
    }
    return 0;
}