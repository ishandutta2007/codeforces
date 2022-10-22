#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n, p;
char str[Maxn];
char res[Maxn];

void Print()
{
    res[n] = '\0';
    printf("%s\n", res);
}

int main()
{
    scanf("%d %d", &n, &p);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        res[i] = str[i] == '.'? '0': str[i];
    for (int i = 0; i < n && i < p; i++) {
        vector <int> dots;
        bool was0 = false, was1 = false;
        for (int j = i; j < n; j += p)
            if (str[j] == '.') dots.push_back(j);
            else if (str[j] == '1') was1 = true;
            else if (str[j] == '0') was0 = true;
        if (was0 && was1) { Print(); return 0; }
        if (!dots.empty() && was0) { res[dots[0]] = '1'; Print(); return 0; }
        if (!dots.empty() && was1) { Print(); return 0; }
        if (dots.size() >= 2) { res[dots[0]] = '1'; Print(); return 0; }
    }
    printf("No\n");
    return 0;
}