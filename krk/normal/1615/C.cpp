#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
char A[Maxn];
char B[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        int res = Maxn;
        vector <int> dif0, dif1;
        vector <int> sam0, sam1;
        for (int i = 0; i < n; i++)
            if (A[i] == '0')
                if (B[i] == '0') sam0.push_back(i);
                else dif0.push_back(i);
            else if (B[i] == '1') sam1.push_back(i);
                 else dif1.push_back(i);
        if (dif0.size() == dif1.size()) res = min(res, int(dif0.size()) + int(dif1.size()));
        if (sam0.size() + 1 == sam1.size()) res = min(res, int(sam0.size()) + int(sam1.size()));
        printf("%d\n", res >= Maxn? -1: res);
    }
    return 0;
}