#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, l, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> m >> l;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    if (data[0] > l) ++ans;
    for (int i = 1; i < n; i++)
        {
        if (data[i] > l && data[i-1] <= l) ++ans;
        }

    for (int i = 0; i < m; i++)
        {
        cin >> tmp;
        if (tmp == 0)
            {
            cout << ans << endl;
            }
        else
            {
            cin >> a >> b;
            --a;
            if (data[a] > l) continue;
            data[a]+= b;
            if (data[a] <= l) continue;

            ++ans;

            if (a != 0)
                if (data[a-1] > l) --ans;

            if (a != n-1)
                if (data[a+1] > l) --ans;
            }
        }

    return 0;
    }