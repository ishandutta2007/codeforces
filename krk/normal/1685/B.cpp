#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int a, b, c, d;
char str[Maxn];
int slen;
int cnt[2];

void Process(int len, int &ndA, int &ndB)
{
    int tk = min(len / 2, ndA);
    len -= 2 * tk; ndA -= tk;
    if (len) {
        tk = min((len - 1) / 2, ndB);
        ndB -= tk;
    }
}

bool Solve()
{
    cnt[0] = cnt[1] = 0;
    for (int i = 0; i < slen; i++)
        cnt[str[i] - 'A']++;
    if (cnt[0] != a + c + d || cnt[1] != b + c + d)
        return false;
    int ndA = c, ndB = d;
    vector <int> evA, oddA;
    vector <int> evB, oddB;
    for (int i = 0, j; i < slen; i = j) {
        j = i + 1;
        while (j < slen && str[j] != str[j - 1]) j++;
        int len = j - i;
        if (len % 2 == 0)
            if (str[i] == 'A') evA.push_back(len);
            else evB.push_back(len);
        else if (str[i] == 'A') oddA.push_back(len);
             else oddB.push_back(len);
    }
    sort(evA.begin(), evA.end());
    for (int i = 0; i < evA.size(); i++)
        Process(evA[i], ndA, ndB);
    sort(oddA.begin(), oddA.end());
    for (int i = 0; i < oddA.size(); i++)
        Process(oddA[i], ndA, ndB);
    sort(evB.begin(), evB.end());
    for (int i = 0; i < evB.size(); i++)
        Process(evB[i], ndB, ndA);
    sort(oddB.begin(), oddB.end());
    for (int i = 0; i < oddB.size(); i++)
        Process(oddB[i], ndB, ndA);
    return ndA == 0 && ndB == 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        scanf("%s", str); slen = strlen(str);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}