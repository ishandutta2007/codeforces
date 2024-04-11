#include <bits/stdc++.h>

#define S second
#define F first

using namespace std;
typedef long long ll;


int main()
{
    int m[3];
    cin >> m[0] >> m[1] >> m[2];
    sort(m, m + 3);
    cout << m[2] - m[1] + m[1] - m[0];

}