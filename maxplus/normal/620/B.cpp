#include <iostream>

using namespace std;

int main()
{
    int a, b, i, arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, ans = 0;
    cin >> a >> b;
    while ((i = a++) <= b)
        do  ans += arr[i % 10], i /= 10;
        while (i);
    cout << ans;
    return 0;
}