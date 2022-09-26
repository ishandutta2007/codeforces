#include<bits/stdc++.h>
using namespace std;
int read()
{
    int v = 0, f = 1;
    char c = getchar();
    while (c < 48 || 57 < c) {if (c == '-') f = -1; c = getchar();}
    while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
    return v * f;
}

const int N = 1000;

string s, t;
char ch[N];

string ans[N];
map<string, vector<string> > mp;

bool pre(string &a, string &b)
{
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i]) return 0;
    return 1;
}

int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int k = read();
        while (k--)
        {
            scanf("%s", ch);
            reverse(ch, ch + strlen(ch));
            t = ch;
            for (int i = 0; ch[i]; i++) ch[i] = 0;
            mp[s].push_back(t);
        }
    }
    printf("%ld\n", mp.size());
    for (map<string, vector<string> > :: iterator i = mp.begin(); i != mp.end(); i++)
    {
        cout << (*i).first;
        vector<string> &p = (*i).second;
        sort(p.begin(), p.end());
        int len = 0;
        for (int j = 0; j < p.size(); )
        {
            int k;
            for (k = j + 1; k < p.size(); k++)
                if (!pre(p[k - 1], p[k])) break;
            ans[++len] = p[k - 1];
            j = k;
        }
        printf(" %d", len);
        for (int i = 1; i <= len; i++)
        {
            printf(" ");
            for (int j = ans[i].length() - 1; j >= 0; j--)
                printf("%c", ans[i][j]);
        }
        puts("");
    }
}