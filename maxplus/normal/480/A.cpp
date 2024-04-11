#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#define f first
#define s second
#define N 5000

using namespace std;

pair<int, int> a[N];
int n, t;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].f >> a[i].s;
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        if (t <= a[i].s)
            t = a[i].s;
        else
            t = a[i].f;
    }
    cout << t;
    return 0;
}