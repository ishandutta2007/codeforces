#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

string data;

long long a, b, k, n, m, tmp;
int ans = 0;





int main()
    {
    FAST;


    cin >> n >> k;

    cin >> data;

    int ansers [40] = {};

    int i = 0;
    while (i < n)
        {
        char lettter = data[i];
        int j = i;
        while (j < n-1)
            {
            if (data[j+1] != lettter) break;

            j++;
            }

        ansers[lettter-'a']+= (j-i+1)/k;

        i = j+1;
        }


    for (int i = 0; i < 40; i++)
        {
        ans = max(ans, ansers[i]);
        }
    cout << ans;

    return 0;
    }