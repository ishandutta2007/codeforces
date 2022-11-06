#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, a, b, aa, bb;
long long sum;
vector<pair<int, int> > inGame;

bool cmp(pair<int, int> A, pair<int, int> B) {
    return A.first + A.second > B.first + B.second;
}

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &a, &b, &aa, &bb);
        if (a <= bb && b <= aa) {
            continue;
        }
        if (a > bb && a + b <= aa + bb) {
            sum += a - bb;
        }
        if (b > aa && a + b <= aa + bb) {
            sum -= b - aa;
        }
        if (a + b > aa + bb) {
            inGame.push_back({a, b});
            inGame.push_back({aa, bb});
        }
    }

    sort(inGame.begin(), inGame.end(), cmp);

    for (int i = 0; i < inGame.size(); i++) {
        if (i % 2 == 0) {
            sum += inGame[i].first;
        } else {
            sum -= inGame[i].second;
        }
    }

    printf("%lld\n", sum);

    return 0;
}