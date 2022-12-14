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



    int Cur_NOD = 1;

    while (n > 3)
        {
        for (int i = 0; i < (n+1)/2; i++)
            {
            cout << Cur_NOD << " ";
            }


        n/= 2;
        Cur_NOD*= 2;
        }


    if (n == 1)
        {
        cout << Cur_NOD;
        return 0;
        }
    else if (n == 2)
        {
        cout << Cur_NOD << " " << 2*Cur_NOD;
        return 0;
        }
    else if (n == 3)
        {
        cout << Cur_NOD << " " << Cur_NOD << " " << 3*Cur_NOD;
        return 0;
        }


    return 0;
    }