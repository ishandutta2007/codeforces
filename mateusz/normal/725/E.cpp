#include <bits/stdc++.h>

using namespace std;

const int N = 300005, INF = 1e9;

int n, c;
int coin[N], firstLower[N];
long long pref[N];

bool canGet(int sum, int maxPos) {
    if (sum == 0) {
        return true;
    }
    int fl = min(maxPos, firstLower[sum]);
    if (fl == 0) {
        return false;
    }

    int low = 1;
    int high = fl;
    int res = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (pref[fl] - pref[mid - 1] <= sum) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return canGet(sum - pref[fl] + pref[res - 1], res - 1);
}

int main() {

    scanf("%d %d",  &c, &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &coin[i]);
    }

    sort(coin + 1, coin + 1 + n);

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + coin[i];
    }

    int cur = 0;
    for (int i = 1; i <= c; i++) {
        while (cur < n && coin[cur + 1] <= i) {
            cur++;
        }
        firstLower[i] = cur;
    }

    vector<int> used;
    int rem = c;
    int sum = 0;
    for (int i = n; i >= 1; i--) {
        if (coin[i] <= rem) {
            rem -= coin[i];
            sum += coin[i];
            used.push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= c; i++) {
        while (!used.empty() && coin[used.back()] < i) {
            sum -= coin[used.back()];
            used.pop_back();
        }
        if (i > c - sum) {
            continue;
        }
        int last = used.empty() ? n : (used.back() - 1);
        if (!canGet(c - sum - i, last)) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("Greed is good\n");
    return 0;
}