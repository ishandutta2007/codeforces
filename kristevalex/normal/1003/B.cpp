#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long a, b, x, ans;


int main()
    {
    FAST;

    cin >> a >> b >> x;

    if ((x/2)*2 != x)
        {
        for (int i = 0; i < a-x/2; i++)
            {
            cout << 0;
            }
        for (int i = 0; i < x/2; i++)
            {
            cout << 1 << 0;
            }
        for (int i = 0; i < b-x/2; i++)
            {
            cout << 1;
            }
        }
    else
        {
        if (a > b)
            {
            for (int i = 0; i < a-x/2; i++)
                {
                cout << 0;
                }
            for (int i = 0; i < b-x/2+1; i++)
                {
                cout << 1;
                }
            cout << 0;
            for (int i = 0; i < x/2-1; i++)
                {
                cout << 1 << 0;
                }


            }
        else
            {
            for (int i = 0; i < b-x/2; i++)
                {
                cout << 1;
                }
            for (int i = 0; i < a-x/2+1; i++)
                {
                cout << 0;
                }
            cout << 1;
            for (int i = 0; i < x/2-1; i++)
                {
                cout << 0 << 1;
                }

            }
        }


    return 0;
    }