
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string a;
        cin >> a;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 'b')
            {
                cout << "b";
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(a[i] != 'b')
            {
                cout << a[i];
            }
        }
        cout << "\n";
    }
    return 0;
}