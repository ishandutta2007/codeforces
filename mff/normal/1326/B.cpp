#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int m = 0;

    for (int i = 0; i < n; ++i)
    {
        int b;
        cin >> b;
        int a = b + m;
        m = max(a, m);
        cout << a << " ";
    }

    cout << endl;

    return 0;
}