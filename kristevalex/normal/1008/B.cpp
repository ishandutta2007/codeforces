#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, m, k, ans;


int main()
    {
    FAST;

    cin >> n;

    vector<long long> dataMAX (n);
    vector<long long> dataMIN (n);
    vector<long long> data (n);


    for (int i = 0; i < n; i++)
        {
        cin >> m >> k;
        dataMAX[i] = max(m, k);
        dataMIN[i] = min(m, k);
        }

    data[0] = dataMAX[0];

    for (int i = 1; i < n; i++)
        {
        if (dataMAX[i] <= data[i-1])
            {
            data[i] = dataMAX[i];
            }
        else
            {
            if (dataMIN[i] <= data[i-1])
                {
                data[i] = dataMIN[i];
                }
            else
                {
                cout << "NO";
                return 0;
                }
            }

        }


    cout << "YES";

    return 0;
    }