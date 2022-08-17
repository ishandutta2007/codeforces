#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 1000111222, inf = 1000111222;

int get_dsum(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> ans;
    for (int sum = 0; sum <= 100; ++sum) {
        int prev_n = n - sum;
        if (prev_n <= 0) continue;

        if (get_dsum(prev_n) == sum) {
            ans.PB(prev_n);
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a << endl;
    }
    cout << endl;
    return 0;
}