#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



char ansers[200] = {};

int main()
    {
    FAST;

    map<int, int> Map;


    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        Map[data[i]]++;
        }


    int counter1 = 0;
    int ind3 = -1;
    for (auto it = Map.begin(); it != Map.end(); ++it)
        {
        if (it->second == 1) counter1++;
        if (it->second >= 3) ind3 = it->first;
        }

    if (counter1 & 1 && ind3 == -1)
        {
        cout << "NO";
        return 0;
        }

    cout << "YES" << endl;

    if (counter1 & 1)
        {
        counter1/= 2;

        for (int i = 0; i < n; i++)
            {
            if (Map[data[i]] == 1 && counter1 > 0)
                {
                counter1--;
                ansers[i] = 'B';
                }
            else ansers[i] = 'A';

            if (data[i] == ind3)
                {
                ind3 = -1;
                ansers[i] = 'B';
                }
            }
        }
    else
        {
        counter1/= 2;

        for (int i = 0; i < n; i++)
            {
            if (Map[data[i]] == 1 && counter1 > 0)
                {
                counter1--;
                ansers[i] = 'B';
                }
            else ansers[i] = 'A';
            }
        }

    for (int i = 0; i < n; i++)
        {
        cout << ansers[i];
        }
    cout << endl;

    return 0;
    }