#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
const int maxn = 1e5 + 20;
ld abbs(ld a)
{
    if(a < 0)
        return -a;
    return a;
}
ld res , _min = 1e18;
int node;
int main()
{
    int n;
    ld a;
    cin >> n >> a;
    res = (n - 2) * 180 / (ld)n;
    res /= (n - 2);
    for(int i = 1; i <= n - 2; i++)
    {
        if(abbs(a - res * i) < _min)
        {
            _min = abbs(a - res * i);
            node = i;
        }
    }
    cout << "2 1 " << node + 2 << endl;
}