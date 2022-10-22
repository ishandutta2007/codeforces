#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int Ask(int a, int b)
{
    printf("? %d %d\n", a, b); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int getBest(int a, int b)
{
    int got = Ask(a, b);
    return got == 1? a: b;
}

void Answer(int x)
{
    printf("! %d\n", x); fflush(stdout);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <int> seq;
        for (int i = 1; i <= 1 << n; i++)
            seq.push_back(i);
        while (seq.size() >= 4) {
            vector <int> nw;
            for (int i = 0; i < seq.size(); i += 4) {
                int a = seq[i], b = seq[i + 1], c = seq[i + 2], d = seq[i + 3];
                int got = Ask(a, c);
                if (got == 0) nw.push_back(getBest(b, d));
                else if (got == 1) nw.push_back(getBest(a, d));
                else if (got == 2) nw.push_back(getBest(b, c));
            }
            seq = nw;
        }
        if (seq.size() == 2) {
            int a = seq[0], b = seq[1];
            seq.clear();
            seq.push_back(getBest(a, b));
        }
        Answer(seq[0]);
    }
    return 0;
}