#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

char str[1000000];
int slen;
bool win[Maxl][2];

int main()
{
    scanf("%s", str); slen = strlen(str);
    int g = 0;
    for (int i = 0; i < slen; i++) {
        int let = str[i] - 'a';
        bool w = false;
        for (int j = 0; j < let; j++)
            if (win[j][0]) w = true;
        win[let][w] = true;
        printf("%s\n", !w? "Mike": "Ann");
    }
    return 0;
}