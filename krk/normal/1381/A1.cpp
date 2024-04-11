#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

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
        int fir = 0, sec = n - 1;
        bool lef = true;
        vector <int> res;
        for (int i = n - 1; i >= 0; i--)
            if (lef) {
                if (A[sec] != B[i]) {
                    if (A[fir] == B[i])
                        res.push_back(0);
                    res.push_back(i);
                    fir++;
                    lef = !lef;
                } else sec--;
            } else if (A[fir] == B[i]) {
                if (A[sec] != B[i])
                    res.push_back(0);
                res.push_back(i);
                sec--;
                lef = !lef;
            } else fir++;
        printf("%d", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf(" %d", res[i] + 1);
        printf("\n");
    }
    return 0;
}