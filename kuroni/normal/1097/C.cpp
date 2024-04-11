#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int N = 500005;

int n, ans = 0, cnt[N];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--)
    {
        cin >> s;
        int cur = 0, sum = 0;
        for (char &c : s)
            if (c == '(')
            {
                sum++;
                cur++;
            }
            else
            {
                sum--;
                cur = max(0, cur - 1);
            }
        if (sum == 0 && cur == 0)
        {
            if (cnt[0] > 0)
            {
                ans++;
                cnt[0]--;
            }
            else
                cnt[0]++;
        }
        else if (sum > 0 && cur == sum)
        {
            if (cnt[sum] < 0)
                ans++;
            cnt[sum]++;
        }
        else if (sum < 0 && cur == 0)
        {
            if (cnt[-sum] > 0)
                ans++;
            cnt[-sum]--;
        }
    }
    cout << ans;
}