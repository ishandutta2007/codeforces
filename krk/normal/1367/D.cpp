#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;
const int Maxl = 26;

int q;
string s;
int freq[Maxl];
int m;
int b[Maxn];
char res[Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        cin >> s;
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;
        int pnt = 'z' - 'a';
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        while (true) {
            vector <int> seq;
            for (int i = 1; i <= m; i++)
                if (b[i] == 0) {
                    seq.push_back(i);
                    b[i] = -1;
                }
            if (seq.empty()) break;
            while (freq[pnt] < seq.size()) pnt--;
            for (int i = 0; i < seq.size(); i++)
                res[seq[i]] = pnt + 'a';
            pnt--;
            for (int i = 1; i <= m; i++) if (b[i] >= 0)
                for (int j = 0; j < seq.size(); j++)
                    b[i] -= abs(i - seq[j]);
        }
        res[m + 1] = '\0';
        printf("%s\n", res + 1);
    }
    return 0;
}