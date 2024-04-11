#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <string>

using namespace std;

#define MAX 1000
#define MAXK 100000

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    string s;
    cin >> s;

    int n = s.size();

    int last_num = s[n - 1] - '0';
    int best_swap_index = -1;
    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        if (num % 2 == 0) {
            if (num < last_num) {
                best_swap_index = i;
                break;
            } else if (best_swap_index < 0 || (s[best_swap_index] > s[n - 1] && num > last_num)) {
                best_swap_index = i;
            }
        }
    }

    if (best_swap_index >= 0) {
        char tmp = s[best_swap_index];
        s[best_swap_index] = s[n - 1];
        s[n - 1] = tmp;
        cout << s << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}