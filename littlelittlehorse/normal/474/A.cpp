#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

string  a[3] = {
"qwertyuiop",
"asdfghjkl;",
"zxcvbnm,./"};
char str[11], str2[111];
int n;

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%s%s", str, str2);
    n = strlen(str2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < a[j].size(); k++)
                if (a[j][k] == str2[i])
                    if (str[0] == 'R') printf("%c", a[j][k - 1]);
                    else printf("%c", a[j][k + 1]);
    printf("\n");
}