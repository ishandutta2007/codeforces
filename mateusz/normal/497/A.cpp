#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
typedef long long LL;

using namespace std;
const int N = 1005;
char s[N][N];
bool jestgut[N];
int wynik = 0;
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%s", &s[i][1]);
    for(int i=1; i<=m; i++)
    {
        bool usuwam = false;
        for(int j=2; j<=n; j++)
        {
            if(s[j][i] < s[j - 1][i] && !jestgut[j]) {
                usuwam = true;
                wynik++;
                break;
            }
        }
        if(usuwam == false) {
            for(int j=2; j<=n; j++)
            {
                if(s[j][i] > s[j - 1][i]) jestgut[j] = true;
            }
        }
    }
    printf("%d", wynik);
    return 0;
}