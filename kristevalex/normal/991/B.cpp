#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n;



int main()
    {
    FAST;

    cin >> n;

    long long neaded = (9*n + 1)/2;

    vector <long long> data (n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    sort(data.begin(), data.end());

    long long sum = 0;

    for (int i = 0; i < n; i++)
        sum+= data[i];


    if (sum >= neaded)
        {
        cout << 0;
        return 0;
        }

    for (int i = 0; i < n; i++)
        {
        sum+= (5-data[i]);
        if (sum >= neaded)
            {
            cout << i+1;
            return 0;
            }
        }

    while (true) {}

    return 0;
    }