#include <bits/stdc++.h>
using namespace std;

int T;
int n;

bool Sorted(const vector <int> &V)
{
    for (int i = 1; i < V.size(); i++)
        if (V[i] < V[i - 1]) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <int> od, ev;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (a % 2) od.push_back(a);
            else ev.push_back(a);
        }
        printf("%s\n", Sorted(od) && Sorted(ev)? "Yes": "No");
    }
    return 0;
}