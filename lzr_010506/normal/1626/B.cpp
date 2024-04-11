#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T --)
    {
        string a;
        cin >> a;
        int n = a.size();
        for(int i = n - 1; i > 0; i --)
        {
            int p = a[i] - '0' + a[i - 1] - '0';
            if(p > 9) {a[i - 1] = p / 10 + '0', a[i] = p % 10 + '0'; cout << a << "\n"; goto L1;} 
        }
        cout << (int)(a[0] - '0') + (a[1] - '0');
        for(int i = 2; i < n; i ++) cout << a[i];
        cout << "\n";
        L1:;
    }
}