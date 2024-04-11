#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        printf("%s\n", n % 4? "NO": "YES");
    }
    return 0;
}