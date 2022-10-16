#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    int ans = d1 + d2 + d3;
    ans = min(ans, 2 * (d1 + d3));
    ans = min(ans, 2 * (d2 + d3));
    ans = min(ans, 2 * (d1 + d2));
    cout << ans << endl;
    
    //system("pause");
    return 0;
}