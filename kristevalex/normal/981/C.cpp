
#include <bits/stdc++.h>
using namespace std;



int n;


//vector<pair<int, int>> data;


int main()
    {
    cin >> n;

    //data.resize(n);

    vector<int> vers(2*(n-1));

    //BIG_NUM = 1000000000;


    for (int i = 0; i < n-1; i++)
        {
        cin >> vers[2*i] >> vers[2*i+1];
        }


    /*int ver1 = data[0].first, ver2 = data[0].second;

    for (int i = 1; i < n-1; i++)
        {
        if (ver1 != data[i].first && ver1 != data[i].second) ver1 = -1;
        if (ver2 != data[i].first && ver2 != data[i].second) ver2 = -1;
        }

    if (ver1 != -1)
        {
        cout << "Yes" << endl;
        cout << n-1 << endl;
        for (int i = 0; i < n-1; i++)
            {
            cout << data[i].first << " " << data[i].second << endl;
            }
        return 0;
        }

    if (ver2 != -1)
        {
        cout << "Yes" << endl;
        cout << n-1 << endl;
        for (int i = 0; i < n-1; i++)
            {
            cout << data[i].first << " " << data[i].second << endl;
            }
        return 0;
        }

            */

    sort(vers.begin(), vers.end());

    stack<int> vis_ver;
    stack<int> exx;


    for (int i = 0; i < 2*(n-1); )
        {
        int current = vers[i];
        int j = i+1;
        for ( ; j < 2*(n-1); j++)
            {
            if (vers[j] != current) break;
            }
        if (j-i >= 3) exx.push(current);
        if (j-i == 1) {vis_ver.push(current); /*cout << "pushing: " << i << " " << j << endl;*/}
        i = j;
        }


    /*for (int i = 0; i < 2*(n-1); i++)
        {
        if (i == 0)
            {
            if (vers[0] != vers[1]) vis_ver.push(vers[0]);
            continue;
            }
        if (vers[i] == vers[i-1])
            {
            continue;
            }
        if (i == 2*(n-1)-1)
            {
            vis_ver.push(vers[i]);

            break;
            }
        if (vers[i] == vers[i+1])
            {
            continue;
            }
        vis_ver.push(vers[i]);

        //cout << vers[i] << endl;
        }        */

    if (vis_ver.size() == 2)
        {
        cout << "Yes" << endl << 1 << endl;
        cout << vis_ver.top() << " ";
        vis_ver.pop();
        cout << vis_ver.top();
        return 0;
        }

    if (exx.size() == 1)
        {
        cout << "Yes" << endl << vis_ver.size() << endl;
        while (!vis_ver.empty())
            {
            cout << vis_ver.top() << " " << exx.top() << endl;
            vis_ver.pop();
            }
        return 0;
        }

    /*while (!vis_ver.empty())
        {
        cout << vis_ver.top() << endl;
        vis_ver.pop();
        }*/

    cout << "No";
    return 0;
    }