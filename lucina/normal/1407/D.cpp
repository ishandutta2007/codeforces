#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int nax = 3e5 + 10;
int n;
int h[nax];
int dp[nax];
/// fine fine, I'll write stack

int main() {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d", h + i);


    vector < int> stk1, stk2;
    stk1.push_back(1), stk2.push_back(1);

    for (int i = 2 ; i <= n ; ++ i) {
        dp[i] = dp[i - 1] + 1;
        /**
                |
          |     |
       |  |     |
        */
        if (!stk1.empty() && h[stk1.back()] == h[i])
            dp[i] = min(dp[i], dp[stk1.back()] + 1);

        if (!stk2.empty() && h[stk2.back()] == h[i])
            dp[i] = min(dp[i], dp[stk2.back()] + 1);

        while (!stk1.empty() && h[i] >= h[stk1.back()]) {
            int v = h[stk1.back()];
            stk1.pop_back();
            if (h[i] != v && !stk1.empty())
                dp[i] = min(dp[i], dp[stk1.back()] + 1);
        }

        /**
             _ _
            |   |
            |   |
            |   |
            |   |
        */

        while (!stk2.empty() && h[i] <= h[stk2.back()]) {
            int v = h[stk2.back()];
            stk2.pop_back();///
            if (h[i] != v && !stk2.empty())
                dp[i] = min(dp[i], dp[stk2.back()] + 1);
        }
        stk1.push_back(i);
        stk2.push_back(i);
    }
    printf("%d\n", dp[n]);



}
/**
    Why 9am tomorrow?
    :sad face
*/