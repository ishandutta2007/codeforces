#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    cout << (a == b ? "YES" : "NO");

}