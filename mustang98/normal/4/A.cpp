#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int max_n = 100009;

int parent[max_n], sz[max_n];

int Main()
{
    int w;
    cin >> w;
    if (w % 4 == 0) 
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}

/*
ll bp(ll sum)
{
    ll* a = upper_bound(z2p, z2p + k, sum);
    if (a == z2p) return 0;
    else return *(z2 + (a - z2p) - 1);
    int l = 0, r = k - 1;
    if (z2[l].S > sum) return 0;
    if (z2[r].S <= sum) return z2[k - 1].F;
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (z2[mid].S <= sum)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return z2[l].F;
}
*/




int main()
{
    int w;
    cin >> w;
    if (w > 2 && w % 2 == 0) 
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}