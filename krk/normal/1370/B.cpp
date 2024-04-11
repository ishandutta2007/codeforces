#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n;
vector <int> ev, od;

int main()
{
    scanf("%d", &T);
    while (T--) {
        ev.clear(); od.clear();
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            int a; scanf("%d", &a);
            if (a % 2 == 0) ev.push_back(i);
            else od.push_back(i);
        }
        if (ev.size() % 2 == 1) {
            ev.pop_back();
            od.pop_back();
        } else if (ev.size() > 0) {
            ev.pop_back();
            ev.pop_back();
        } else {
            od.pop_back();
            od.pop_back();
        }
        for (int i = 0; i < ev.size(); i += 2)
            printf("%d %d\n", ev[i], ev[i + 1]);
        for (int i = 0; i < od.size(); i += 2)
            printf("%d %d\n", od[i], od[i + 1]);
    }
    return 0;
}