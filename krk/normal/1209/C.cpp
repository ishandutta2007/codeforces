#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int t;
int n;
char str[Maxn];
char res[Maxn];

bool Check(int dig)
{
    char lst1 = '0';
    char lst2 = dig + '0';
    for (int i = 0; i < n; i++)
        if (lst2 <= str[i]) { res[i] = '2'; lst2 = str[i]; }
        else if (lst1 <= str[i]) { res[i] = '1'; lst1 = str[i]; }
        else return false;
    return lst1 <= dig + '0';
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", str);
        int p = 0;
        while (p < 10 && !Check(p)) p++;
        if (p >= 10) printf("-\n");
        else {
            res[n] = '\0';
            printf("%s\n", res);
        }
    }
    return 0;
}