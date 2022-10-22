#include <iostream>
#include <string>
using namespace std;

const string vowels = "aeiou";

int n, k;
bool aabb = true, abab = true, abba = true, aaaa = true;

bool R(const string &a, const string &b)
{
     int lft = k;
     int i;
     for (i = a.length(); i >= 0; i--)
         if (vowels.find(a[i]) != string::npos)
            if (--lft == 0) break;
     if (i < 0) return false;
     lft = k;
     int j;
     for (j = b.length(); j >= 0; j--)
         if (vowels.find(b[j]) != string::npos)
            if (--lft == 0) break;
     if (j < 0) return false;
     return a.substr(i, a.length() - i) == b.substr(j, b.length() - j);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s[4];
        for (int j = 0; j < 4; j++) cin >> s[j];
        if (!R(s[0], s[1]) || !R(s[2], s[3])) aabb = false;
        if (!R(s[0], s[2]) || !R(s[1], s[3])) abab = false;
        if (!R(s[0], s[3]) || !R(s[1], s[2])) abba = false;
        if (!R(s[0], s[1]) || !R(s[0], s[2]) || !R(s[0], s[3]) ||
            !R(s[1], s[2]) || !R(s[1], s[3]) || !R(s[2], s[3])) aaaa = false;
    }
    if (aaaa) cout << "aaaa\n";
    else if (aabb) cout << "aabb\n";
    else if (abab) cout << "abab\n";
    else if (abba) cout << "abba\n";
    else cout << "NO\n";
    return 0;
}