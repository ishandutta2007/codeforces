#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long f[100001][2][2][2], ans1, ans2;
char str[100001];

int main(){
    scanf("%s", str);
    n = strlen(str);
    memset(f, 0, sizeof(f)); ans1 = ans2 = 0;
    ans1 = f[0][str[0] - 'a'][str[0] - 'a'][1] = 1;
    for (int i = 1; i < n; i++)
    {
        f[i][0][str[i] - 'a'][0] = f[i - 1][0][str[i] - 'a'][1] + f[i - 1][0][(str[i] - 'a') ^ 1][1];
        f[i][1][str[i] - 'a'][1] = f[i - 1][1][str[i] - 'a'][0] + f[i - 1][1][(str[i] - 'a') ^ 1][0];
        f[i][0][str[i] - 'a'][1] = f[i - 1][0][str[i] - 'a'][0] + f[i - 1][0][(str[i] - 'a') ^ 1][0];
        f[i][1][str[i] - 'a'][0] = f[i - 1][1][str[i] - 'a'][1] + f[i - 1][1][(str[i] - 'a') ^ 1][1];
        f[i][str[i] - 'a'][str[i] - 'a'][1]++;
        ans1 += f[i][0][0][1] + f[i][1][1][1];
        ans2 += f[i][0][0][0] + f[i][1][1][0];
    }
    printf("%I64d %I64d\n", ans2, ans1);
}