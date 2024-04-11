#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, tmp;


int main()
    {
    FAST;

    map<long long, bool> MAP;

    cin >> n;


    for (int i = 0; i < n; i++)
        {
        cin >> tmp;
        if (tmp != 0)
            MAP[tmp] = true;
        }





    cout << MAP.size();

    return 0;
    }