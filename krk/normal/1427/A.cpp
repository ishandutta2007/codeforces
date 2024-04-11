#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n, a;
bool was;

void Print(const vector <int> &V)
{
    for (int i = 0; i < V.size(); i++) {
        if (was) printf(" ");
        else was = true;
        printf("%d", V[i]);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sum = 0;
        vector <int> pos, zer, neg;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            sum += a;
            if (a > 0) pos.push_back(a);
            else if (a == 0) zer.push_back(a);
            else if (a < 0) neg.push_back(a);
        }
        if (sum == 0) printf("NO\n");
        else {
            printf("YES\n");
            was = false;
            if (sum < 0) swap(pos, neg);
            Print(pos);
            Print(zer);
            Print(neg);
            printf("\n");
        }
    }
    return 0;
}