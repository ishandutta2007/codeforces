#include <bits/stdc++.h>

#define F first
#define S second
#define prev privet1

using namespace std;
typedef long long ll;

const int max_n = 100009;

int main()
{
    int n = 0, a = 0, b = 0;
    int m[max_n];
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        if (s[i] == 'A') a++;
        else b++;
    }
    if (a > b) cout << "Anton";
    else if (a < b) cout << "Danik";
    else cout << "Friendship";
    return 0;
}