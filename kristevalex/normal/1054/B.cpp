#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;

    int Max = 0;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];



    for (int i = 0; i < n; i++)
        {
        if (data[i] > Max)
            {
            cout << i+1;
            return 0;
            }

        if (data[i] == Max) Max++;
        }



    cout << -1;

    return 0;
    }