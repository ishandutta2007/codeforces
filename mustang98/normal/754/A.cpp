#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

const int max_n = 1000111;
const int max_sqrt = 1111;

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int m[1000];
    int n;
    bool isnonz = false;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> m[i];
        sum += m[i];
        if (m[i]) isnonz = true;
    }
    if (isnonz == false)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    if (sum)
    {
        cout << "1\n" << 1 << ' ' << n << "\n";
        return 0;
    }
    
    cout << 2 << endl;
    
    int lastnonz = n - 1;
    while (m[lastnonz] == 0)
    {
        lastnonz--;
    }
    
    cout << 1 << ' ' << lastnonz <<endl;
    cout << lastnonz + 1 << ' ' <<n;
    
    return 0;
}