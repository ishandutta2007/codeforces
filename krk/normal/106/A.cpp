#include <iostream>
#include <string>
using namespace std;

const string ranks = "6789TJQKA";

char trump;
string a, b;

int main()
{
    cin >> trump;
    cin >> a >> b;
    if (ranks.find(a[0]) > ranks.find(b[0]) && a[1] == b[1] ||
        a[1] == trump && b[1] != trump) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}