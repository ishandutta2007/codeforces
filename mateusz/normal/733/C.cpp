#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k;
int initSeq[N], endSeq[N];
vector<pair<int, char> > eating;

void processEating(int from, int to) {
    int mx = from;
    for (int i = from; i <= to; i++) {
        if (initSeq[i] > initSeq[mx]) {
            mx = i;
        }
    }
    if (to - from + 1 == 1) {
        return;
    }
    bool isSmaller = false;
    for (int i = from; i <= to; i++) {
        if (initSeq[i] < initSeq[mx]) {
            isSmaller = true;
            break;
        }
    }
    if (!isSmaller) {
        printf("NO\n");
        exit(0);
    }
    for (int i = from; i <= to; i++) {
        if (initSeq[i] == initSeq[mx] && ((i > from && initSeq[i - 1] < initSeq[i]) || (i < to && initSeq[i + 1] < initSeq[i]))) {
            if (i > from && initSeq[i - 1] < initSeq[i]) {
                for (int j = i - 1; j >= from; j--) {
                    eating.push_back({i - eating.size(), 'L'});
                }
                int currentEating = eating.size();
                for (int j = i + 1; j <= to; j++) {
                    eating.push_back({i - currentEating, 'R'});
                }
            } else {
                int currentEating = eating.size();
                for (int j = i + 1; j <= to; j++) {
                    eating.push_back({i - currentEating, 'R'});
                }
                for (int j = i - 1; j >= from; j--) {
                    eating.push_back({i - currentEating, 'L'});
                    currentEating++;
                }
            }
            return;
        }
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &initSeq[i]);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &endSeq[i]);
    }

    int cur = 1;
    int curSum = 0;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (cur > k || curSum + initSeq[i] > endSeq[cur]) {
            printf("NO\n");
            return 0;
        }
        curSum += initSeq[i];
        if (curSum == endSeq[cur]) {
            processEating(last + 1, i);
            last = i;
            cur++;
            curSum = 0;
        }
    }
    if (cur <= k) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (int i = 0; i < eating.size(); i++) {
        printf("%d %c\n", eating[i].first, eating[i].second);
    }

    return 0;
}