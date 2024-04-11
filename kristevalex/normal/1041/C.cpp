#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

set<pair<long long, int>> data;
vector<long long> ansers;

long long a, b, k, d, n, m, tmp, ans = 0;


long long day = 0;


int main()
    {
    FAST;


    cin >> n >> m >> d;

    //data.resize(n);
    ansers.resize(n);

    for (int i = 0; i < n; i++)
        {
        pair<long long, int> Tmp;
        cin >> Tmp.first;
        Tmp.second = i;

        data.insert(Tmp);
        }


    //sort(data.begin(), data.end());




    while (!data.empty())
        {
        day++;

        pair<long long, int> prev (-d-5, -1);

        auto it = data.begin();
        while (it != data.end())
            {
            ansers[it->second] = day;

            long long next = it->first+d+1;

            data.erase(it);


            it = data.lower_bound(pair<long long, int>(next, -1));
            }
        }

    for (int i = 0; i < n; i++)
        {
        if (ansers[i] > ans) ans = ansers[i];
        }

    cout << ans << endl;

    for (int i = 0; i < n; i++)
        cout << ansers[i] << " ";

    return 0;
    }