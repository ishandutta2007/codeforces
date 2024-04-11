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

    string text;
    cin >> text;



    for (int i = 0; i < n-1; i++)
        {
        if (text[i] > text[i+1])
            {
            for (int j = 0; j < n; j++)
                {
                if (j != i) cout << text[j];
                }
            return 0;
            }
        }


    for (int j = 0; j < n-1; j++)
        {
        cout << text[j];
        }



    return 0;
    }