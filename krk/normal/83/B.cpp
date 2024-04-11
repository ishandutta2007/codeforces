#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

ll n, k;
int nil, lft[Maxn];

ll Calc(int x)
{
    ll res = 0;
    for (int i = 0; i < n; i++)
       res += min(x, lft[i]);
    return res;
}

void Search(int l, int r)
{
     if (l > r) return;
     int mid = (l + r) / 2;
     if (Calc(mid) <= k) {
                   nil = mid;
                   Search(mid + 1, r);
     } else Search(l, mid - 1);
}

int main()
{
    ll sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> lft[i]; sum += lft[i];
    }
    if (sum < k) { cout << "-1\n"; return 0; }
    Search(0, 1000000000);
    k -= Calc(nil);
    int first = 0;
    while (k) {
          if (lft[first] > nil) {
                         lft[first]--;
                         k--;
          }
          first++;
    }
    bool printed = false;
    for (int i = first; i < n; i++) if (lft[i] > nil) {
        if (printed) cout << " ";
        printed = true;
        cout << i + 1;
    }
    for (int i = 0; i < first; i++) if (lft[i] > nil) {
        if (printed) cout << " ";
        printed = true;
        cout << i + 1;
    }
    cout << endl;
    return 0;
}