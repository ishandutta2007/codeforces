#include <iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w, h, u1, d1, u2, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    if(d1 < d2)
    {
        swap(d1, d2);
        swap(u1, u2);
    }
    //cout << (h - d1 + 1) * (h + d1);
    int sum = w + (h - d1 + 1) * (h + d1) /2;
    //cout << sum;
    sum -= u1;
    if(sum < 0)
    {
        sum = 0;
    }
    sum += (d1 - d2) * (d1 + d2 -1) / 2;
    //cout << sum;
    sum -= u2;
    if(sum < 0)
    {
        sum = 0;
    }
    sum += d2 * (d2 - 1) / 2;
    cout << sum;
    return 0;
}