#include <bits/stdc++.h>
using namespace std;

typedef pair <char, int> ci;

const int Maxn = 200005;

int T;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", &str);
        slen = strlen(str);
        char a = str[0], b = str[slen - 1];
        if (a > b) swap(a, b);
        vector <ci> seq;
        seq.push_back(ci(str[0], 0));
        for (int i = 1; i + 1 < slen; i++)
            if (a <= str[i] && str[i] <= b)
                seq.push_back(ci(str[i], i));
        seq.push_back(ci(str[slen - 1], slen - 1));
        sort(seq.begin() + 1, seq.end() - 1);
        if (str[0] > str[slen - 1])
            reverse(seq.begin() + 1, seq.end() - 1);
        printf("%d %d\n", int(b - a), int(seq.size()));
        for (int i = 0; i < seq.size(); i++)
            printf("%d%c", seq[i].second + 1, i + 1 < seq.size()? ' ': '\n');
    }
    return 0;
}