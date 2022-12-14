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

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];


    for (int i = 0; i < n; i++)
        {
        ans+= data[i];
        }



    cout << ((ans)? "HARD" : "EASY");

    return 0;
    }