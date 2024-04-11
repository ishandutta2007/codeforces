#include <iostream>
#include <algorithm>
using namespace std;

const int Inf = 100000;
const int Maxn = 105;

int n, x;
int a[Maxn], b[Maxn];
int best = Inf;

bool Valid(int x)
{
     for (int i = 0; i < n; i++)
         if (x < a[i] || x > b[i]) return false;
     return true;
}

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    for (int i = 0; i <= 1000; i++)
        if (Valid(i)) best = min(best, abs(i - x));
    if (best == Inf) cout << "-1\n";
    else cout << best << endl;
    return 0;
}