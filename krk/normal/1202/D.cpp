#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int t;
int x;
char res[Maxn];
int rlen;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        vector <int> seq;
        while (x > 0) {
            int a = 1;
            while (a * (a - 1) / 2 <= x) a++;
            a--;
            seq.push_back(a);
            x -= a * (a - 1) / 2;
        }
        reverse(seq.begin(), seq.end());
        rlen = 0;
        res[rlen++] = '1';
        int lst = 0;
        for (int i = 0; i < seq.size(); i++) {
            int add = seq[i] - lst; lst = seq[i];
            while (add--) res[rlen++] = '3';
            res[rlen++] = '7';
        }
        res[rlen] = '\0';
        printf("%s\n", res);
    }
    return 0;
}