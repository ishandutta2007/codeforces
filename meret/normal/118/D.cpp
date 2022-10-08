/* Order: Jacob, Jakub */
#include <stdio.h> // recurrence with a[n] and b[n], a[n] is number of beautiful arrangements ending with a footman
#include <algorithm> // I would suggest dp with dp1[a][b] = number of arrangements using a footmen, b horsemen and ending with a footman (dp2 similarly)
int mod = 100000000; // oops yeah misread the problem, I agree with you
int dp1[105][105], dp2[105][105];
int main(){
    int n1, n2, k1, k2;
    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
    dp1[0][0] = dp2[0][0] = 1;
    for(int a = 0; a <= n1; a++){
        for (int b = 0; b <= n2; ++b) {
            for(int cur_num_footmen = 1; cur_num_footmen <= k1 && cur_num_footmen + a <= n1; cur_num_footmen++){
                dp1[a + cur_num_footmen][b] = (dp1[a + cur_num_footmen][b] + dp2[a][b]) % mod;
            }
            for (int cur_num_horsemen = 1; cur_num_horsemen <= std::min(k2, n2 - b); ++cur_num_horsemen) {
                dp2[a][b + cur_num_horsemen] = (dp2[a][b + cur_num_horsemen] + dp1[a][b]) % mod;
            }
        }
    }
    printf("%d\n", (dp1[n1][n2] + dp2[n1][n2]) % mod); // n1 and n2 are both >= 1 so we don't have to worry about this being wrong for dp[0][0]
} // submiit