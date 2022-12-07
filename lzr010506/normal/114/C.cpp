#include <bits/stdc++.h>
using namespace std;
vector < pair <int, int> > a;
#define T first
#define G second

bool Check(string s1, string s2) 
{
    if (s1.size() < s2.size()) return false;
    int j = s2.size() - 1;
    for (int i = s1.size() - 1; i >= 0; i--)
        if (s1[i] == s2[j]) 
        {
            --j;
            if (j < 0) return true;
        } else break;
    return false;
}

bool OK(int lo, int hi) 
{
    int cnt = 0, pos;
    for(int i = lo; i <= hi; i ++)
        if (a[i].T == 2) ++cnt, pos = i;
    if (cnt != 1) return false;

    for (int j = pos - 1; j >= 0; j--)
        if (a[j].T != 1) return false;
    for (int j = pos + 1; j < a.size(); j++)
        if (a[j].T != 3) return false;

    return true;
}
int main() 
{
	string s;
    while (cin >> s)
        if (Check(s, "lios"))
            a.push_back(make_pair(1, 1));
        else if (Check(s, "liala"))
            a.push_back(make_pair(1, 2));
        else if (Check(s, "etr"))
            a.push_back(make_pair(2, 1));
        else if (Check(s, "etra"))
            a.push_back(make_pair(2, 2));
        else if (Check(s, "initis"))
            a.push_back(make_pair(3, 1));
        else if (Check(s, "inites"))
            a.push_back(make_pair(3, 2));
        else 
        {
            puts("NO");
            return 0;
        }

    if (a.size() == 1) 
    {
        puts("YES");
        return 0;
    }

    for (int i = 0; i < a.size(); ) 
    {
        int j = i;
        while (j + 1 < a.size() && a[i].G == a[j + 1].G) ++j;

        if (!OK(i, j) || j != a.size() - 1) 
        {
            puts("NO");
            return 0 ;
        }

        i = j + 1;
    }

    puts("YES");
    return 0;
}