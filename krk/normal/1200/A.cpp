#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10;

int n;
string s;
bool tk[Maxn];

int main()
{
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'L') {
            int pnt = 0;
            while (tk[pnt]) pnt++;
            tk[pnt] = true;
        } else if (s[i] == 'R') {
            int pnt = Maxn - 1;
            while (tk[pnt]) pnt--;
            tk[pnt] = true;
        } else {
            int ind = s[i] - '0';
            tk[ind] = false;
        }
    for (int i = 0; i < Maxn; i++)
        printf("%c", tk[i]? '1': '0');
    printf("\n");
    return 0;
}