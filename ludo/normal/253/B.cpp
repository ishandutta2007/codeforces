#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

int n, a[MAX];

bool can_be_made(int i)
{
    for (int left = 0; left <= i; left++) {
        if (a[n - 1 - i + left] <= 2 * a[left]) {
//            cerr << i << ": " << left << " - " << (n - left + i - 1) << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
#ifndef LOCAL
    freopen("output.txt", "w", stdout);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(&a[0], &a[n]);

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

//        bool b = can_be_made(mid);
//        cerr << mid << ": " << b << endl << endl;
//        if (b) {
        if (can_be_made(mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
//       cout << endl << endl << low << ", " << high << endl;
    return 0;
}