#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


string text;


int main()
    {
    FAST;


    cin >> n;

    cin>>text;

    for (int i = 0; i < n-1; i++)
        {
        if (text[i] != text[i+1])
            {
            cout << "YES" << endl;
            cout << text[i] << text[i+1];
            return 0;
            }
        }




    cout << "NO";

    return 0;
    }