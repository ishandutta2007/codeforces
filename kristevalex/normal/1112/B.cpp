#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(0); \
             cout.tie(0) \

#define pii pair<int, int>
#define ll long long

vector<ll> data;

long long a, b, n, m, k, tmp, ans = 0;


int main ()
    {
    FAST;

    cin >> n >> k;

    data.resize(n);

    for (int i = 0; i < n; ++i)
        {
        cin >> data[i];
        }

    vector<int> times(200001, 0);

    vector<int> t (n, -1);

    int _min = 0;
    int _max = 0;

    vector<int> proc (k, 0);
    for (int i = 0; i < 200000; ++i)
        {
        for (int j = 0; j < k; ++j)
            {
            if (proc[j] == i)
                {
                if (i != 0) _max++;

                if (_min < n)
                    {
                    proc[j] = i + data[_min];
                    t[_min] = i;


                    ++_min;
                    }
                }
            }
        times[i] = (_max*200 + n)/(2*n);
        }

    for (int i = 0; i < 200; ++i)
        {
        //cout << i << " " << times[i] << endl;
        }

        //cout<< "\n\n\n";

    for (int i = 0; i < n; ++i)
        {
        for (int j = 0; j < data[i]; ++j)
            {
            //cout << "{ " <<  t[i] << " " << j+1 << " }";

            if (j+1 == times[t[i]+j])
                {
                //cout << i << " t[i]: " << t[i] << " " << j << " _ " << times[t[i]+j] << endl;

                ++ans;
                break;
                }
            }
        //cout << "\n\n";
        }

    cout << ans;
    /*for (int i = 0; i < n; ++i)
        {
        cout << t[i] << endl;
        }*/
    }