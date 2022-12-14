#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


bool ask (long long x, long long y)
    {
    cout << x << " " << y << endl;
    fflush(stdout);
    cout.flush();

    string text;
    cin >> text;
    return text == "Yes";
    }


int main()
    {
    srand(time(nullptr)+2345*time(nullptr));

    FAST;


    cin >> n >> k;

    long long l = 1, r = n;



    while (true)
        {
        //for (int i = 0; i < 100; i++)
        //    {}


        if (r-l+1 > 9*k+10)
            {

            if (ask(1, (l+r)/2))
                {
                if (r == l) return 0;

                l = max(l-k-1, 1ll);
                r = min((l+r)/2+k+1, n);
                }
            else
                {
                l = max((l+r)/2-k-1, 1ll);
                r = min(r+k+1, n);
                }
            }
        else
            {
            int shuffle = rand()%(r-l+1);


            if (ask(l+shuffle, l+shuffle)) return 0;


            l = max(l-k-1, 1ll);
            r = min(r+k+1, n);
            }
        }


    return 0;
    }