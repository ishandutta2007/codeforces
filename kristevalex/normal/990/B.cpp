#include <bits/stdc++.h>
using namespace std;



int n, K;




int main()
    {
    cin >> n >> K;


    vector<int> data (n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    sort(data.begin(), data.end());

    int ans = n;


    for (int i = 0; i < n-1; )
        {
        int j = i+1;
        while (j < n-1 && data[j] == data[i]) j++;

        if (data[i] < data[j] && data[i]+K >= data[j])
            {
            ans-= j-i;
            //cout << data[i] << endl;
            }
        i = j;
        }

    cout << ans;



    return 0;
    }