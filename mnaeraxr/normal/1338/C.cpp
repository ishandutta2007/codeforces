#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

long long find(long long t, long long pow) {
    if (t == 0)
        return 0;

    long long block = t / pow;

    long long cur = find(t % pow, pow / 4);
    long long head = 0;

    if (block == 0){
        head = 0;
    } else if (block == 1) {
        head = pow * 2;
    } else if (block == 2) {
        head = pow * 3;
    } else {
        head = pow;
    }

    return head | cur;

}

long long solve(long long n) {
    if (n <= 3) return n;

    long long pow = 4;
    while (pow <= n) {
        pow *= 4;
    }
    pow /= 4;

    auto nn = n - pow; // pos in
    auto tn = nn / 3; // triplet

    auto left = nn / 3 + pow;

    // cout << nn << " " << tn << " " << left << " " << pow << " ";

    if (nn % 3 == 0)
        return left;


    long long npow = 4;
    while (npow <= tn)
        npow *= 4;
    npow /= 4;

    auto middle = find(tn, npow) | (pow * 2);

    if (nn % 3 == 1)
        return middle;
    else
        return left ^ middle;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // for (int i = 1; i <= 100; i += 3) {
    //     cout << solve(i) << " " << solve(i + 1) << " " << solve(i + 2) << endl;
    // }

    // cout << solve(7) << endl;
    // return 0;

    int t; cin >> t;

    while (t--) {
        long long n; cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}