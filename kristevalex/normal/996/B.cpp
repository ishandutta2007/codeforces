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


    vector <long long> data (n);


    long long min_num = -1, min_value = LLONG_MAX;

    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        data[i]+= n-i-1;
        data[i]/= n;

        if (data[i] < min_value)
            {
            min_value = data[i];
            min_num = i+1;
            }
        }

    cout << min_num;

    return 0;
    }