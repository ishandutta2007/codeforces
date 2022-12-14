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


    cin >> text;



    for (int i = 0; i < text.size()-1; i++)
        {
        if (text[i] == text[i+1])
            {
            cout << 0 << " ";
            }
        else cout << 1 << " ";
        }




    if (text[text.size()-1] == 'a') cout << 1;
    else cout << 0;

    return 0;
    }