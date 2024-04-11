#include <iostream>
#include <string>
using namespace std;

const string byt = "127";
const string shor = "32767";
const string in = "2147483647";
const string lon = "9223372036854775807";

int main()
{
    string s;
    cin >> s;
    if (s.length() < byt.length() || s.length() == byt.length() && s <= byt) cout << "byte\n";
    else if (s.length() < shor.length() || s.length()== shor.length() && s <= shor) cout << "short\n";
    else if (s.length() < in.length() || s.length() == in.length() && s <= in) cout << "int\n";
    else if (s.length() < lon.length() || s.length() == lon.length() && s <= lon) cout << "long\n";
    else cout << "BigInteger\n";
    return 0;
}