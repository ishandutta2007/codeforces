#include <bits/stdc++.h>
using namespace std;


int n, k;
vector<int> data;
map<int, pair<int, int>> MAP;

int main()
    {
    cin >> n;

    for (int i = 0; i < n; i++)
        {
        cin >> k;
        data.resize(k);
        int Sum = 0;
        for (int j = 0; j < k; j++)
            {
            cin >> data[j];
            Sum+= data[j];
            }

        //cout << i;

        for (int j = 0; j < k; j++)
            {
            data[j] = Sum - data[j];
            if (MAP[data[j]].first)
                {
                //cout << "hello" << MAP[data[j]].first << " " << i << endl;
                if (MAP[data[j]].first != i+1)
                    {
                    cout << "YES" << endl;
                    cout << MAP[data[j]].first << " " << MAP[data[j]].second << endl;
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                    }
                }
            else
                {
                MAP[data[j]] = {i+1, j+1};
                //cout << "hel" << data[j]<< " " << i << ", " << j << endl;
                }
            }
        }

    /*for (map<int, pair<int, int>>::iterator it = MAP.begin(); it != MAP.end(); it++)
        {
        cout << it->first << " => {" << it->second.first << ", " << it->second.second << endl;
        }*/

    cout << "NO";


    return 0;
    }