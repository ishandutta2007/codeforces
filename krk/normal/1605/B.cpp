#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        vector <int> res;
        int l = 0, r = n - 1;
        while (l < r)
            if (str[l] == '0') l++;
            else if (str[r] == '1') r--;
            else {
                res.push_back(l + 1);
                res.push_back(r + 1);
                l++; r--;
            }
        sort(res.begin(), res.end());
        if (res.empty()) printf("0\n");
        else {
            printf("1\n");
            printf("%d", int(res.size()));
            for (int i = 0; i < res.size(); i++)
                printf(" %d", res[i]);
            printf("\n");
        }
    }
    return 0;
}