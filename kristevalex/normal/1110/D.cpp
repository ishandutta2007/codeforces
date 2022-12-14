#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

int a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> m;



    vector<int> cnt_ (1e6+27, 0);

    for (int i = 0; i < n; i++)
        {
        cin >> tmp;
        cnt_[tmp+2]++;
        }




    vector<vector<int>> dp (1e6+27, vector<int>(9, 0));


    for (int i = 1e6+17; i >= 0; i--)
        {

        for (int j = 0; j < 9; j++)
            {
            int a = cnt_[i] - j/3 - j%3;
            int b = cnt_[i+1] - j/3;
            int c = cnt_[i+2];

            int MIN = min (c, min (a, b));
            MIN = min(MIN, 2);

            for (int delta = 0; delta <= MIN; delta++)
                {
                dp[i][j] = max(dp[i][j], (a-delta)/3 + delta + dp[i+1][j/3 + 3*delta]);
                }



            }
        }


    for (int i = 0; i < 9; i++)
        {
        ans = max(ans, dp[0][i]);
        }

    cout << ans;

    return 0;
    }
/*
16 1000
1 2 2 3 3 3 4 4 4 4 5 5 5 6 6 7

*/