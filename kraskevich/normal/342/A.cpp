#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    vector<int> cnt(8, 0);
    vector<int> f, s, l;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int x = 7; x >= 1; x--)
    {
        while (cnt[x])
        {
            l.push_back(x);
            cnt[x]--;
            int mid = 0;
            for (int j = x - 1; j >= 1; --j)
                if (cnt[j] && x % j == 0)
                {
                    mid = j;
                    break;
                }
            if (!mid)
            {
                cout << -1;
                return 0;
            }
            cnt[mid]--;
            s.push_back(mid);
            int small = 0;
            for (int j = mid - 1; j >= 1; --j)
                if (cnt[j] && mid % j == 0)
                {
                    small = j;
                    break;
                }
            if (!small)
            {
                cout << -1;
                return 0;
            }
            cnt[small]--;
            f.push_back(small);
        }
    }
    for (int i = 0; i < n / 3; i++)
        cout << f[i] << " " << s[i] << " " << l[i] << "\n";


    return 0;
}