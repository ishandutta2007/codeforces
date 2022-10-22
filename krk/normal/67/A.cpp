#include <iostream>
#include <string>
using namespace std;

const int Maxn = 1000;

int n, a[Maxn];
string s;

int main()
{
    cin >> n >> s;
    a[0] = 1;
    for (int i = 0; i < n-1; i++)
       if (s[i] == 'L') {
                a[i+1] = 1;
                for (int j = i; j >= 0; j--)
                   if (s[j] == 'L' && a[j] <= a[j+1]) a[j] = a[j+1] + 1;
                   else if (s[j] == '=' && a[j] < a[j+1]) a[j] = a[j+1];
       } else if (s[i] == 'R') a[i+1] = a[i] + 1;
       else a[i+1] = a[i];
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}