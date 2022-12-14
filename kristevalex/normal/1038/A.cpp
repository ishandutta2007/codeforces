#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<char> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> k;

    data.resize(n);

    int Map[300] = {};



    for (int i = 0; i < n; i++)
        {
        cin >> data[i];

        Map[data[i]]++;
        }


    long long Min = 100000000;

    for (int i = 'A'; i < 'A'+k; i++)
        {
        if (Map[i] < Min) Min = Map[i];
        }

    cout << Min*k;

    return 0;
    }