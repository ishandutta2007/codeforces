#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> ansers;

long long a, b, k, x, y, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;
    ansers.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> x >> y >> k;
        x = abs(x);
        y = abs(y);



        if (max(x, y) > k)
            {
            ansers[i] = -1;
            continue;
            }

        if ((x+y) & 1)
            {
            ansers[i] = k-1;
            continue;
            }
        else
            {
            /*if (k == 1)
                {
                ansers[i] = -1;
                continue;
                } */
            //cout << (((x+y)/2)%2) << " " << k%2 << endl;
            if (((  max(x, y)  )%2) != (k%2)) ansers[i] = k-2;
            else ansers[i] = k;
            continue;
            }


        }



    for (int i = 0; i < n; i++)
        {
        cout << ansers[i] << endl;
        }


    return 0;
    }