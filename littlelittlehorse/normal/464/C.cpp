#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int P = 1000000007;
string str;
string str1[110001], str2[110001], str3[110001];
int n, m;
long long f[110001][10], v[110001][10];

int main(){
  //   freopen("c.in", "r", stdin);
  //   freopen("c.out", "w", stdout);
     cin >> str; n = str.size();
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) 
     {
          cin >> str1[i]; int len = str1[i].size();
          str2[i] = str3[i] = "";
          for (int j = 0; j < len; j++)
               if (str1[i][j] == '-')
               {
                    for (int k = 0; k < j; k++) str2[i] += str1[i][k];
                    for (int k = j + 2; k < len; k++) str3[i] += str1[i][k];
                    break;
               }
     }
     str2[0] = "0"; str3[0] = str;
     for (int i = 0; i < 10; i++) f[n + 1][i] = i, v[n + 1][i] = 10;  
     for (int i = n; i >= 0; --i)
          for (int j = 0; j < 10; j++)
               if (j != str2[i][0] - '0') f[i][j] = f[i + 1][j], v[i][j] = v[i + 1][j];
               else
               {
                    f[i][j] = 0; v[i][j] = 1;
                    int len = str3[i].size();
                    for (int k = len - 1; k >= 0; --k)
                         f[i][j] += f[i + 1][str3[i][k] - '0'] * v[i][j] % P,
                         f[i][j] %= P,
                         v[i][j] *= v[i + 1][str3[i][k] - '0'], v[i][j] %= P;
               }
     printf("%d\n", f[0][0]);                    
}