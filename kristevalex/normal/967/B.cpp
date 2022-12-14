#include <bits/stdc++.h>
using namespace std;

long long n, A, B;







bool compare (int a, int b)
    {
    return a > b;
    }


int main()
    {
    cin >> n >> A >> B;

    vector<long long> data(n);



    for (long long i = 0; i < n; i++)
        {
        cin >> data[i];
        }

    if (n == 1)
        {
        cout << 0;
        return 0;
        }

    sort(data.begin()+1, data.end());

    for (long long i = 1; i < n; i++)
        {
        data[i]+= data[i-1];
        if (data[0]*A < data[i]*B)
            {
            cout << n-i;
            return 0;
            }
        }

    cout << 0;



    return 0;
    }