#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, i = 0, curr_ans = 0;

string data1, data2;


int main()
    {
    FAST;

    cin >> data1 >> data2;

    n = data1.size();

    for ( ; i < n-1; i++)
        {
        if (data1[i] == 'X' && data2[i] == 'X') continue;
        if (data1[i] == '0' && data2[i] == '0')
            {
            if (data1[i+1] == 'X' && data2[i+1] == 'X') continue;

            curr_ans++;

            if (data1[i+1] == '0')
                {
                data1[i+1] = 'X';
                continue;
                }
            if (data2[i+1] == '0')
                {
                data2[i+1] = 'X';
                continue;
                }

            int x = 5/0;
            }

        if (data1[i+1] == '0' && data2[i+1] == '0')
            {
            i++;
            curr_ans++;
            continue;
            }
        }


    cout << curr_ans;

    return 0;
    }