#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0, sum = 0;;





int main()
    {
    FAST;


    cin >> n;

    data.resize(n);

    string text;
    cin >> text;

    for (int i = 0; i < n; i++)
        {
        data[i] = text[i]-'0';
        sum+= data[i];
        }

    if (sum == 0)
        {
        cout << "YES";
        return 0;
        }

    for (int line = 1; line < 10000; line++)
        {
        long long cur_sum = 0;
        bool ok = true;

        for (int i = 0; i < n; i++)
            {
            cur_sum+= data[i];
            if (cur_sum == line) cur_sum-= line;
            if (cur_sum > line)
                {
                ok = false;
                break;
                }
            }

        if (ok && sum%line == 0 && sum != line)
            {
            cout << "YES";
            return 0;
            }
        }


    cout << "NO";

    return 0;
    }