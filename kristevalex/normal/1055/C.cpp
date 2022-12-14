#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a1, b1, t1, a2, b2, t2, k, n, m, tmp, ans = 0;



long long get_(long long dist)
    {
    long long _start = max(0ll, dist);

    long long _end = min(b1-a1, b2-a2+dist);

      //cout << _start << " " << _end <<  " " << dist  <<  endl;
    return max(_end - _start, 0ll);
    }

int main()
    {
    FAST;


    cin >> a1 >> b1 >> t1 >> a2 >> b2 >> t2;
    ++b1;
    ++b2;

    if (a1 > a2)
        {
        swap(a1, a2);
        swap(b1, b2);
        swap(t1, t2);
        //cout << "kef\n";
        }

    k = __gcd(t1, t2);
    long long dist = a2-a1;
    dist%= k;




    cout << max(get_(dist), get_(dist-k));

    return 0;
    }