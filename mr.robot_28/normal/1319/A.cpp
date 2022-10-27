#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> p1(n), p2(n);
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> p1[i];
        sum1 += p1[i];
    }
    for(int j = 0; j < n; j++)
    {
        cin >> p2[j];
        sum2 += p2[j];
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(p1[i] == 1 && p2[i] == 0)
        {
            cnt1++;
        }
    }
    if(sum1 > sum2)
    {
        cout << 1;
    }
    else if(cnt1 == 0)
    {
        cout << -1;
    }
    else
    {
        cout << (sum2 - sum1 + 1 + cnt1 - 1) / cnt1 + 1;
    }
    return 0;
}