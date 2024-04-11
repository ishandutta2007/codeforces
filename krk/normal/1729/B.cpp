#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        vector <int> V;
        int pnt = n - 1;
        while (pnt >= 0)
            if (str[pnt] == '0') {
                V.push_back(int(str[pnt - 2] - '0') * 10 + int(str[pnt - 1] - '0'));
                pnt -= 3;
            } else {
                V.push_back(int(str[pnt] - '0'));
                pnt--;
            }
        for (int i = int(V.size()) - 1; i >= 0; i--)
            printf("%c", V[i] - 1 + 'a');
        printf("\n");
    }
    return 0;
}