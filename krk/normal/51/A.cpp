#include <iostream>
#include <set>
#include <string>
using namespace std;

int n;
set <string> piles;

int main()
{
    int i;
    string s, ss, a, b, c;
    cin >> n;
    for (i = 0; i < n; i++) {
        if (i) cin >> ss;
        cin >> s >> ss;
        s += ss[1]; s += ss[0];
        a = s[3]; a += s[0]; a += s[1]; a += s[2];
        b = s[2]; b += s[3]; b += s[0]; b += s[1];
        c = s[1]; c += s[2]; c += s[3]; c += s[0];
        if (piles.count(s) == 0 && piles.count(a) == 0 &&
            piles.count(b) == 0 && piles.count(c) == 0)
            piles.insert(s);
    }
    cout << piles.size() << endl;
    return 0;
}