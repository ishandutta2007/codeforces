#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long n = 1000000, m = 1000000, x, y, tmp, middle;


int main()
    {
    FAST;


    cin >> n >> m;

    middle = (n*n+1)/2;

    data.resize(m);


    for (int i = 0; i < m; i++)
        {
        cin >> y >> x;

        if ((x+y)&1)
            {
            data[i] = middle+1;
            }
        else
            {
            data[i] = 1;
            }

        x+= (y-1)*n-1;

        x/= 2;

        data[i]+= x;
        }


    for (int i = 0; i < m; i++)
        {
        cout << data[i] << endl;
        }



    return 0;

    }