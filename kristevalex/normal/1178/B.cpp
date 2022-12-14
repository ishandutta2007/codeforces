#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

string data;

long long a, b, k, n, m, tmp, ans = 0;

#define ll long long





int main()
    {
    FAST;


    cin >> data;
    n = data.size();

    ll w = 0, wo = 0, wow = 0;


    char type = data[0];
    ll cnt = 1;
    for (int i = 1; i < n; i++)
        {

        if (type == data[i]) ++cnt;
        else
            {

            //cout << cnt << " ";
            if (type == 'o')
                {
                wo+= w*cnt;
                }
            else
                {
                --cnt;
                w+= cnt;
                wow+= cnt*wo;
                }

            //cout << w << " " << wo << " " << wow << endl;


            cnt = 1;
            type = data[i];
            }
        }

    if (type == 'o')
        {
        wo+= w*cnt;
        }
    else
        {
        --cnt;
        w+= cnt;
        wow+= cnt*wo;
        }

   //cout << w << " " << wo << " " << wow << endl;


    cout << wow;

    return 0;
    }