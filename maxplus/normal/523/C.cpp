#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

string s1, s2;

int main()
{
    cin >> s1 >> s2;
    uint32_t lp = 0, rp = s2.size() - 1;
    for (auto i: s1)
        while (lp < s2.size() && s2[lp++] != i);
    reverse(s1.begin(), s1.end());
    for (auto i: s1)
        while (rp < s2.size() && s2[rp--] != i);
    cout << max(0, int(rp - lp + 2));
    return 0;
}