#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int a[100 * 1000 * 2];
int n;

bool can(int ans, bool print) {
     vector<int> cur;
     int k = 1;
     cur.push_back(a[0]);
     vector<int> big, middle, small;
     for(int i = 1; i < n; ++i) {
             if(a[i] == a[i - 1])
                     ++k;
             else
                 k = 1;
             if(k <= ans)
                  cur.push_back(a[i]);
     }
     k = ans;
     for(int i = 0; i + 2 * k < cur.size(); ++i) {
             big.push_back(cur[i]);
             middle.push_back(cur[i + k]);
             small.push_back(cur[i + 2 * k]);
     }
     if(print) {
               cout << ans << endl;
               for(int i = 0; i < ans; ++i)
                      cout << big[i] << " " << middle[i] << " " << small[i] << endl;
     }
     return big.size() >= ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    int l = 0, r = n;
    while(l < r - 1) {
            int m = (l + r) / 2;
            if(can(m, false))
                      l = m;
            else
                r = m;
    }
    if(can(r, false))
              ++l;
    can(l, true);
    cin >> n;
    return 0;
}