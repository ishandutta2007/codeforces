#include <bits/stdc++.h>
#include <string>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000009;

vector<string> word;
vector<int> ch;

vector<string> dep[max_n];

string s;

string parsefrom(int ind)
{
    string ans;
    int k = 0;
    int i = ind;
    while(i < s.size() && s[i] != ',')
    {
        i++;
        k++;
    }
    ans = s.substr(ind, k);
    return ans;
}

int maxlvl = -1;

int f(int cur, int lvl)
{
    maxlvl = max(maxlvl, lvl);
    dep[lvl].push_back(word[cur]);
    int kch = ch[cur];
    cur++;
    for (int i = 0; i < kch; i++)
    {
        cur = f(cur, lvl + 1);
    }
    return cur;
}

int main()
{
    //ifstream cin("input.txt");
    cin >> s;
    char sch[10];
    int cur = 0;
    while(cur < s.size())
    {
        string s1 = parsefrom(cur);
        cur += s1.size() + 1;
        string s2 = parsefrom(cur);
        cur += s2.size() + 1;
        /*int i;
        for (i = 0; i < s2.size(); i++)
        {
            sch[i] = s2[i];
        }
        sch[i] = '\0';
        int curch = atoi(sch);
        */int curch = stoi(s2, nullptr);

        word.push_back(s1);
        ch.push_back(curch);
    }
    cur = 0;
    while (cur != word.size())
    {
        cur = f(cur, 0);
    }
    cout << maxlvl + 1 << endl;
    for (int i = 0; i <= maxlvl; i++)
    {
        for (int j = 0; j < dep[i].size(); j++)
        {
            cout << dep[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}