#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    if(n % 2 == 0)
    {
         cout << n * n / 4 << endl;
         for(int i = 0; i < n / 2; ++i)
                 for(int j = n / 2; j < n; ++j)
                         cout << i + 1 << " " << j + 1 << endl;
    }
    else
    {
        int k1 = n / 2, k2 = n - k1;
        cout << k1 * k2 << endl;
        for(int i = 0; i < k1; ++i)
                for(int j = k1; j < n; ++j)
                        cout << i + 1 << " " << j + 1 << endl;
    }
    
    cin >> n;
    
    return 0;
}