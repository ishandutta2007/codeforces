#include <bits/stdc++.h>

#define S second
#define F first

using namespace std;
typedef long long ll;


int main()
{
    int a, b, c;
    int m[1000];
    //cin >> n;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i) cout << "that ";
        if (i % 2 == 0) cout << "I hate ";
        else cout << "I love ";
    }
    cout << "it";
}