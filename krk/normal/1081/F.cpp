#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;

int n, t;
int res[Maxn];
bool dif[Maxn];

int Ask(int l, int r)
{
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Print()
{
    printf("! ");
    for (int i = 1; i <= n; i++)
        printf("%d", res[i]);
    printf("\n");
    fflush(stdout);
}

int main()
{
    scanf("%d %d", &n, &t);
    if (n == 1) res[1] = t;
    else if (n % 2 == 0) {
        int ones = 0, zers = 0;
        for (int i = 1; i <= n; i++) {
            bool invodd = false, inveven = false;
            int lst = t;
            while (true) {
                int nw = Ask(i, i);
                if (nw % 2 == lst % 2)
                    inveven = !inveven;
                else invodd = !invodd;
                lst = nw;
                bool curmy = invodd, curhis = inveven;
                if (i % 2 == 0) swap(curmy, curhis);
                if (curmy && !curhis) {
                    res[i] = zers + t - ones - 1 == lst;
                    if (res[i]) ones++;
                    else zers++;
                    break;
                }
            }
            while (invodd || inveven) {
                int nw = Ask(i, i);
                if (nw % 2 == lst % 2)
                    inveven = !inveven;
                else invodd = !invodd;
                lst = nw;
            }
        }
    } else {
        int got;
        for (int i = 1; i < n; i++) {
            bool invodd = false, inveven = false;
            int lst = t;
            while (true) {
                int nw = Ask(i, i + 1);
                if (nw % 2 == lst % 2)
                    inveven = !inveven;
                else invodd = !invodd;
                lst = nw;
                bool curmy = invodd, curhis = inveven;
                if (i % 2 == 1) swap(curmy, curhis);
                if (curmy && !curhis) {
                    if (i > 1) res[i + 1] = lst < got;
                    got = lst;
                    break;
                }
            }
            while (invodd || inveven) {
                int nw = Ask(i, i + 1);
                if (nw % 2 == lst % 2)
                    inveven = !inveven;
                else invodd = !invodd;
                lst = nw;
            }
        }
        int curones = t;
        got = 0;
        for (int i = n; i >= 3; i--) {
            got += 1 - res[i];
            if (res[i] == 1) curones--;
        }
        got += curones;
        for (int i = 2; i >= 1; i--) {
            bool invodd = false, inveven = false;
            int lst = t;
            while (true) {
                int nw = Ask(i, i + 1);
                if (nw % 2 == lst % 2)
                    inveven = !inveven;
                else invodd = !invodd;
                lst = nw;
                bool curmy = invodd, curhis = inveven;
                if (i % 2 == 0) swap(curmy, curhis);
                if (curmy && !curhis) {
                    res[i] = lst < got;
                    got = lst;
                    break;
                }
            }
            while (invodd || inveven) {
                int nw = Ask(i, i + 1);
                if (nw % 2 == lst % 2)
                    inveven = !inveven;
                else invodd = !invodd;
                lst = nw;
            }
        }
    }
    Print();
    return 0;
}