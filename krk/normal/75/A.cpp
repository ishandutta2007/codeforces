#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int a, b, c;

int main()
{
    string sa, sb, sc;
    cin >> a >> b; c = a + b;
    stringstream s1;
    s1 << a; s1 >> sa;
    stringstream s2;
    s2 << b; s2 >> sb;
    stringstream s3;
    s3 << c; s3 >> sc;
    for (int i = 0; i < sa.length(); i++)
       if (sa[i] == '0') sa.erase(i--, 1);
    for (int i = 0; i < sb.length(); i++)
       if (sb[i] == '0') sb.erase(i--, 1);
    for (int i = 0; i < sc.length(); i++)
       if (sc[i] == '0') sc.erase(i--, 1);
    stringstream s4;
    s4 << sa; s4 >> a;
    stringstream s5;
    s5 << sb; s5 >> b;
    stringstream s6;
    s6 << sc; s6 >> c;
    if (a + b == c) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}