#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


long long get_ans(int num)
    {
    int SQRT = sqrt(num);
    long long ret = 0;

    for (int i = 2; i <= SQRT; i++)
        {
        if (num%i == 0) {ret+= i; ret+= num/i;}
        }

    if (SQRT*SQRT == num) ret-= SQRT;

    return ret;
    }


int main()
    {
    FAST;


    cin >> n;

    for (int i = 2; i <= n; i++)
        {
        ans+= get_ans(i);
        }




    cout << ans*4;

    return 0;
    }