# include <iostream>
# include <string>
using namespace std;
bool check(string &s)
{
    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] == s[i + 1]) return false;
    }
    for (int i = 1; i < s.size() - 1; ++i)
    {
        if (s[i - 1] == s[i + 1]) return false;
    }
    cout << s << endl;
    exit(0);
    return true;
}
string q[6] = {
    "abc",
    "acb",
    "bac",
    "bca",
    "cab",
    "cba"
};
int main()
{
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    string t = s;
    char pf = 'a';
    char pl = 'a' + p;
    if (p == 1 || p == 2 && n > 2 || p == 2 && s == "ba" || p == 2 && s == "b")
    {
        puts("NO");
        return 0;
    }
    else if (p == 2)
    {
        if (s == "a")
            cout << "b" << endl;
        else if (s == "ab")
            cout << "ba" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        for (int i = s.size() - 1; i >= 0; --i)
        {
            t = s;
            while (++t[i] < pl)
            {
                if (i == s.size() - 1) check(t);
                for (int k = 0; k < 6; ++k)
                {
                    string f = q[k];
                    int tc = 0;
                    for (int j = i + 1; j < s.size(); ++j)
                    {
                        t[j] = f[tc];
                        ++tc;
                        if (tc == 3) tc = 0;
                    }
                    check(t);
                }
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}