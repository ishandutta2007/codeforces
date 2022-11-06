#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
string number;
int cnt[105];

int main() {

    cin >> n;
    cin >> number;

    for (int i = 0; i < number.size(); i++) {
        cnt[number[i] - 48]++;
    }

    if ((cnt[1] || cnt[2] || cnt[3]) &&
        (cnt[1] || cnt[4] || cnt[7] || cnt[0]) &&
        (cnt[3] || cnt[6] || cnt[9] || cnt[0]) &&
        (cnt[7] || cnt[0] || cnt[9])
    ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}