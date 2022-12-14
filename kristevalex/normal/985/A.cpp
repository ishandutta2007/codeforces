#include <bits/stdc++.h>
using namespace std;


int n;

vector<int> data;


int main()
{
    cin >> n;

    data.resize(n/2);                                    //

    for (size_t i = 0; i < n/2; i++)
        {
        cin >> data[i];
        }

    sort(data.begin(), data.end());

    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < n/2; i++)
        {
        sum1+= abs(2*i+1 - data[i]);

        //cout << abs(2*i+1 - data[i]) << endl;
        }


    for (int i = 0; i < n/2; i++)
        {
        sum2+= abs(2*i+2 - data[i]);
        }

    cout << min(sum1, sum2);


    return 0;
}