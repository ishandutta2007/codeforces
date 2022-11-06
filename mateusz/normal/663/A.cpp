#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

char c;
int value;
int ans[N];

int main() {

    vector<int> signs;
    signs.push_back(1);
    while (true) {
        scanf(" %c", &c);
        if (c == '?') {
            continue;
        }
        if (c == '+') {
            signs.push_back(1);
        } else if (c == '-') {
            signs.push_back(-1);
        } else if (c == '=') {
            scanf(" %d", &value);
            break;
        }
    }

    ans[0] = value;
    int sum = 0;
    for (int i = 1; i < signs.size(); i++) {
        ans[i] = 1;
        sum += signs[i];
    }

    for (int i = 0; i < signs.size(); i++) {
        if (signs[i] > 0) {
            if (sum > 0) {
                if (ans[i] > sum) {
                    ans[i] -= sum;
                    sum = 0;
                    break;
                } else {
                    sum -= ans[i] - 1;
                    ans[i] = 1;
                    continue;
                }
            } else {
                if (ans[i] - sum <= value) {
                    ans[i] -= sum;
                    sum = 0;
                    break;
                } else {
                    sum += value - ans[i];
                    ans[i] = value;
                    continue;
                }
            }
        } else {
            if (sum > 0) {
                if (ans[i] + sum <= value) {
                    ans[i] += sum;
                    sum = 0;
                    break;
                } else {
                    sum -= value - ans[i];
                    ans[i] = value;
                    continue;
                }
            } else {
                if (ans[i] > -sum) {
                    ans[i] += sum;
                    sum = 0;
                    break;
                } else {
                    sum += ans[i] - 1;
                    ans[i] = 1;
                    continue;
                }
            }
        }
    }
    if (sum == 0) {
        printf("Possible\n");
        for (int i = 0; i < signs.size(); i++) {
            if (i > 0) {
                printf(signs[i] > 0 ? "+ " : "- ");
            }
            printf("%d ", ans[i]);
        }
        printf("= %d\n", value);
    } else {
        printf("Impossible\n");
    }

    return 0;
}