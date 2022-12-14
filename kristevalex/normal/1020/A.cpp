#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)




long long n, h, a, b, q;




vector<long long> ansers;


int main()
    {

    cin >> n >> h >> a >> b >> q;

    ansers.resize(q);

    for (int i = 0; i < q; i++)
        {
        long long floor1, floor2, num1, num2;
        cin >> num1 >> floor1 >> num2 >> floor2;

        ansers[i] = abs(floor1 - floor2);



        if (num1 != num2)
            {

            //cout << i << " " << abs(num1 - num2) << endl;
            ansers[i]+= abs(num1 - num2);
            if (floor1 > b && floor2 > b) ansers[i]+= 2*(-b + min(floor1, floor2));
            if (floor1 < a && floor2 < a) ansers[i]+= 2*(-max(floor1, floor2) + a);
            }
        }

    for (int i = 0; i < q; i++)
        {
        cout << ansers[i] << endl;
        }

    return 0;
    }