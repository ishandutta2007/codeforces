#include <bits/stdc++.h>
using namespace std;

int n;

long long tmp;

map<long long, bool> MAP;






int main()
    {
    //cout << (1<< 1);
    cin >> n;
    //MAP.

    vector<long long> data (n);

    for (int i = 0; i < n; i++)
        {
        cin >> tmp;
        data[i] = tmp;
        MAP[tmp] = true;
        }


    sort(data.begin(), data.end());


    for (int i = 0; i < n-2; i++)
        {
        for (long long j = 1; j <= (LONG_MAX-data[i])/2; j = j<<1)
            {
            if (MAP.count(data[i]+j) && MAP.count(data[i]+j*2))
                {
                cout << 3 << endl;
                cout << data[i] << " " << data[i]+j << " " << data[i]+2*j << endl;
                return 0;
                }

            //if (j > (LONG_MAX-data[i])/2) break;
            }
        }



    for (int i = 0; i < n-1; i++)
        {
        for (long long j = 1; j <= (LONG_MAX-data[i]); j = j<<1)
            {

            if (MAP.count(data[i]+j))
                {
                cout << 2 << endl;
                cout << data[i] << " " << data[i]+j << endl;
                //cout << j;
                return 0;
                }

            //if (j > (LONG_MAX-data[i])/2) break;
            }
        }


    cout << 1 << endl;
    cout << data[0] << endl;

    return 0;
    }