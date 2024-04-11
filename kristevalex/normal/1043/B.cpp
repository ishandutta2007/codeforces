#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;
vector<long long> data_;
vector<long long> ansers;

long long a, b, k, n, m, tmp, ans = 0;







int main()
    {
    FAST;


    cin >> n;

    data.resize(n);
    data_.resize(n);

    cin >> data[0];

    data_[0] = data[0];

    for (int i = 1; i < n; i++)
        {cin >> data_[i]; data[i] = data_[i] - data_[i-1];/* cout << data[i] << endl;*/}

    for (int i = 1; i <= n; i++)
        {
        bool ok = true;

        for (int j = 0; j < n; j++)
            {
            if (data[j] != data[(j%i)])
                {
                ok = false;
                break;
                }
            }

        if (ok) ansers.push_back(i);
        }

    cout << ansers.size() << endl;
    for (int i = 0; i < ansers.size(); i++)
        {
        cout << ansers[i] << " ";
        }

    return 0;
    }