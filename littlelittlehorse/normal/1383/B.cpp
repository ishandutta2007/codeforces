#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, test, a[100011];

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        string ans = "DRAW";
        for (int i = 30; i >= 0; i--) {
            int cnt[2] = {0, 0};
            for (int j = 0; j < n; j++) 
                if (a[j] >> i & 1)
                    cnt[1]++;
                else 
                    cnt[0]++;
            if (cnt[1] % 2 == 0) continue;
            ans = cnt[0] % 2 == 1 || cnt[0] % 2 == 0 && cnt[1] % 4 == 1 ? "WIN" : "LOSE";
            break;
        }
        cout << ans << endl;
    }
}