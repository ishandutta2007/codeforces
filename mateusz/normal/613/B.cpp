#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, A, cf, cm;
long long m;
int skill[N], skill2[N], t[N];
long long pref[N];


int firstLower(int w, int l) {
    int low = 1;
    int high = l;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (skill[mid] <= w) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

bool cmp(int a, int b) {
    return skill[a] < skill[b];
}
int main() {

    scanf("%d %d %d %d %lld", &n, &A, &cf, &cm, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &skill[i]);
        t[i] = i;
        skill2[i] = skill[i];
    }
    sort(t + 1, t + 1 + n, cmp);

    sort(skill + 1, skill + 1 + n);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + skill[i];
    }
    skill[n + 1] = A;
    long long requiredMoves = 0;
    long long ans = 0;
    int bestEnd = n + 1;
    int bestMin = 0;
    for (int i = n + 1; i >= 1; i--) {
        requiredMoves += A - skill[i];
        long long remainingMoves = m - requiredMoves;
        if (remainingMoves < 0) {
            break;
        }
        int low = skill[1];
        int high = A;
        int res = low;
        while (low <= high) {
            int mid = ((long long)low + high) / 2;
            int pos = firstLower(mid, i - 1);
            if (pos == 0 || (long long)pos * mid - pref[pos] <= remainingMoves) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if ((long long)cf * (n - i + 1) + (long long)cm * (res) > ans) {
            ans = (long long)cf * (n - i + 1) + (long long)cm * (res);
            bestEnd = i;
            bestMin = res;
        }
    }

    printf("%lld\n", ans);
    int pos = firstLower(bestMin, bestEnd - 1);
    for (int i = 1; i <= pos; i++) {
        skill2[t[i]] = bestMin;
    }
    for (int i = n; i >= bestEnd; i--) {
        skill2[t[i]] = A;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", skill2[i]);
    }

    return 0;
}