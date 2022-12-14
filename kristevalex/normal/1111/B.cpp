#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

long double answer;





int main()
    {
    FAST;


    cin >> n >> k >> m;

    data.resize(n);

    cout << setprecision(15);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    sort(data.begin(), data.end());

    for (int i = n-1; i >= 0; i--)
        {
        ans+= data[i];
        if (i > m) continue;

        long double cur = ans + min(m-i, (n-i)*k);

        cur/= n-i;

        answer = max(answer, cur);
        }




    cout << answer;

    return 0;
    }