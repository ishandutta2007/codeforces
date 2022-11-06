#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n;
char stairs[N];
long long prefUps[N], prefDowns[N];

int main() {

    scanf("%d", &n);
    scanf("%s", &stairs[1]);

    int totalUp = 0, totalDown = 0;
    for (int i = 1; i <= n; i++) {
        if (stairs[i] == 'U') {
            totalUp++;
            prefUps[totalUp] = prefUps[totalUp - 1] + n - i + 1;
        } else {
            totalDown++;
            prefDowns[totalDown] = prefDowns[totalDown - 1] + i;
        }
    }
    int curUp = 0;
    int curDown = totalDown;
    for (int i = 1; i <= n; i++) {
        if (stairs[i] == 'U') {
            curUp++;
        }
        int used = min(curDown, curUp);
        long long ans1 = 2 * ((prefUps[curUp] - prefUps[curUp - used]) - (long long)used * (n - i + 1));
        long long ans2 = 2 * ((prefDowns[totalDown - curDown + used] - prefDowns[totalDown - curDown]) - (long long)used * i);
        if (curDown > used && stairs[i] == 'D') { //Additional from the right
            ans2 += 2 * (prefDowns[totalDown - curDown + used + 1] - prefDowns[totalDown - curDown + used] - i) + i;
        } else if (curUp > used && stairs[i] == 'U') { // Additional form the left
            ans1 += 2 * (prefUps[curUp - used] - prefUps[curUp - used - 1] - (n - i + 1)) + n - i + 1;
        } else if (stairs[i] == 'U') {
            ans1 += i;
        } else { // stairs[i] == 'D'
            ans2 += n - i + 1;
        }
        if (stairs[i] == 'D') {
            curDown--;
        }
        printf("%lld ", ans1 + ans2);
    }
    printf("\n");
    return 0;
}