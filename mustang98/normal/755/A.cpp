#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

bool prime(int a)
{
    if (a == 2 || a == 3)
    {
        return true;
    }
    for (int i = 2; i * i <= a; ++i)
    {
        if (a % i == 0) return false;
    }
    return true;
}

int main()
{
    //ifstream cin("input.txt");
    int n;
    cin >> n;
    for(int m = 1; m <= 1000; ++m)
    {
        if (!prime(n * m + 1))
        {
            cout << m;
            return 0;
        }
    }
    return 0;
}