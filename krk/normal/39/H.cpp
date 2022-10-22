#include <iostream>
using namespace std;

int n;

string toBase(int x)
{
       if (!x) return "";
       return toBase(x / n) + char(x % n + '0');
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++) {
            cout << toBase(i * j);
            if (j + 1 < n) cout << " ";
            else cout << endl;
        }
    return 0;
}