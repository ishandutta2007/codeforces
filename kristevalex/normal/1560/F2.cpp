#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

long long getAns(long long num, long long p10)
{
    num-= num%p10;
    num+=p10;

    int cnt = 0;
    int cn[10] = {};
    vector<int> digits;
    long long n0 = num;
    while (n0 > 0)
    {
        digits.push_back(n0%10);
        n0/=10;
    }

    long long pow10[15] = {};
    pow10[0] = 1;
    for (int i = 1; i < 15; ++i)
    {
        pow10[i] = pow10[i-1]*10;
    }

    int minval = 10;
    for (int i = digits.size()-1; i >= 0; --i)
    {
        if (cnt < k)
        {
            if (cn[digits[i]] > 0)
                cn[digits[i]]++;
            else
            {
                cnt++;
                cn[digits[i]]++;
                minval = min(minval, digits[i]);
            }
        }
        else if (cn[digits[i]] == 0)
        {
            num+=pow10[i]*minval;
        }
    }



    return num;

}

long long getDif(long long digit, int cn[])
{
    for (int i = 0; i < 10; ++i)
    {
        if (cn[(digit + i)%10] != 0)
            return i;
    }
    return 0;
}

int solve(int t)
{
    cin >> n >> k;
    //n = t / 10 + 1;
    //k = t % 10 + 1;

    ans = n;



    int cnt = 0;
    int cn[10] = {};
    vector<int> digits;
    long long n0 = n;
    while (n0 > 0)
    {
        digits.push_back(n0%10);
        n0/=10;
    }

    long long pow10[15] = {};
    pow10[0] = 1;
    for (int i = 1; i < 15; ++i)
    {
        pow10[i] = pow10[i-1]*10;
    }


    n0 = n;

    long long lastd = -1;
    for (int i = digits.size()-1; i >= 0; --i)
    {
        if (cnt < k)
        {
            if (cn[digits[i]] > 0)
                cn[digits[i]]++;
            else
            {
                cnt++;
                cn[digits[i]]++;
                if (cnt == k)
                {
                    ans = getAns(n, pow10[i]);
                    lastd = i;
                    break;
                }
            }
        }
        else
        {

        }
    }

    int mincn = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (cn[i] != 0)
        {
            mincn = i;
            break;
        }
    }


    n0 = n;
    long long nans = n;
    if (lastd != -1)
    {
        for (int i = 0; i < lastd; ++i)
        {
            long long digit = nans / pow10[i];
            digit%= 10;
            long long add = getDif(digit, cn);
            nans+= pow10[i] * add;

            //cout << digit<< "+"<<add <<" (" << pow10[i] << ")"<<endl;
            if (add > 0)
            {
                nans -= nans % pow10[i];
                for (int j = 0; j < i; ++j)
                {
                    nans += mincn * pow10[j];
                }
            }
        }
        n0/=10;
    }
    else
    {
        cout << ans << endl;
        return 0;
    }


    if ((long long)(nans/pow10[lastd]) != (long long)(n/pow10[lastd]))
        cout  << ans << endl;
    else
        cout << nans << endl;

    return 0;
}


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve(t);

    return 0;
}