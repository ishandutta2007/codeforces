#include <iostream>
#include <cstdio>
using namespace std;

int t, cnt[26];
string s;

string query(string s)
{
    string t = "";
    fill(cnt, cnt + 26, 0);
    int mi = 26;
    for (char &c : s)
    {
        mi = min(mi, c - 'a');
        cnt[c - 'a']++;
    }
    for (int i = 0; i < 25; i++)
        if (cnt[i] > 0 && cnt[i + 1] > 0 && cnt[i] + cnt[i + 1] == (int)s.size())
            return "No answer";
    for (int i = 0; i < 24; i++)
        if (cnt[i] > 0 && cnt[i + 1] > 0 && cnt[i + 2] > 0 && cnt[i] + cnt[i + 1] + cnt[i + 2] == (int)s.size())
            return "No answer";
    for (int i = mi + 1; i < 26; i++)
        if (cnt[i] > 0 && (t == "" || abs(i + 'a' - t.back()) > 1))
            while (cnt[i]--)
                t += (char)(i + 'a');
    for (int i = mi; i < 26; i++)
        if (cnt[i] > 0 && (t == "" || abs(i + 'a' - t.back()) > 1))
            while (cnt[i]--)
                t += (char)(i + 'a');
    return t;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        cout << query(s) << '\n';
    }
}