#include <algorithm>
#include <iostream>
using namespace std;

int cnt[2002][2002];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    int a[n], b[n];
    
    for(int i = 0; i < n; ++i)
    {
            cin >> a[i];
            --a[i];
    }
    for(int i = 0; i < n; ++i)
    {
            cin >> b[i];
            --b[i];
    }
    
    int pos[n];
    
    for(int i = 0; i < n; ++i)
            pos[a[i]] = i;
    
    for(int i = 0; i < n; ++i)
            cout << pos[b[i]] + 1 << " ";
    
    cin >> n;
    
    return 0;
}