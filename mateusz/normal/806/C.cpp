#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, id;
int cnt[N], rests[N], cntCopy[N];

int findLower(long long w) {
    long long p = 1;
    int ret = 0;
    for (int i = 0;; i++) {
        if (p <= w) {
            ret = i;
        } else break;
        p *= 2;
    }
    return ret;
}

bool canAchieve(int elements, int rest) {
    for (int i = 0; i < id; i++) {
        cntCopy[i] = cnt[i];
    }
    
    cnt[0] = elements;
    
    for (int i = 1; i <= id; i++) {
        if (cnt[i] > cnt[i - 1]) {
            rest += cnt[i] - cnt[i - 1];
            cnt[i] = cnt[i - 1];
        } else {
            rest = max(0, rest - (cnt[i - 1] - cnt[i]));
        }
        rest += rests[i];
    }
    
    for (int i = 0; i < id; i++) {
        cnt[i] = cntCopy[i];
    }    
    return rest == 0;
}

int main() {

    scanf("%d", &n);
    
    long long p = 1;
    while (p <= 1e12) {
        p *= 2;
        id++;
    }
    
    for (int i = 1; i <= n; i++) {
        long long x;
        scanf("%lld", &x);
        int firstLower = findLower(x);
        if ((1LL << firstLower) == x) {
            cnt[firstLower]++;
        } else {
            rests[firstLower]++;
        }
    }
    
    vector<int> lengths;
    for (int ans = 0; ans <= cnt[0]; ans++) {
        if (canAchieve(cnt[0] - ans, ans)) {
            lengths.push_back(cnt[0] - ans);
        }
    }
    
    if (lengths.size() == 0) {
        printf("-1\n");
    } else {
        sort(lengths.begin(), lengths.end());
        for (int i = 0; i < lengths.size(); i++) {
            printf("%d ", lengths[i]);
        }
    }
    
    return 0;
}