#include <iostream>
#include <string>
using namespace std;

int n;
string a, b;
int mk;
int res1, res2;

bool Loses(char a, char b)
{
    return a == 'R' && b == 'P' || a == 'P' && b == 'S' || a == 'S' && b == 'R';
}

int main()
{
    cin >> n >> a >> b;
    int mk = a.length() * b.length();
    for (int i = 0; i < mk && i < n; i++) {
        int tims = 1 + (n - i - 1) / mk;
        res1 += Loses(a[i % a.length()], b[i % b.length()]) * tims;
        res2 += Loses(b[i % b.length()], a[i % a.length()]) * tims;
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}