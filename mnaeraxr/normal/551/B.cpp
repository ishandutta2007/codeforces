#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
//#include <bits/stdc++.h>

using namespace std;

#define wait system("pause")

const int oo = 0x3f3f3f3f;

typedef long long int64;

int T[3][26];
int tmp[26];

int getC(int b)
{
    int tot = 1000000;
    for (int i = 0; i < 26; ++i)
    {
        if (b * T[1][i] > T[0][i]) return -1;
        tmp[i] = T[0][i] - b * T[1][i];
        
        if (T[2][i])
           tot = min(tot, tmp[i] / T[2][i]);
    }
    return tot;
}

int main()
{         
          string a, b, c;
          cin >> a >> b >> c;
          
          for (int i = 0; i < (int)a.length(); ++i)
              T[0][a[i] - 'a']++;
          for (int i = 0; i < (int)b.length(); ++i)
              T[1][b[i] - 'a']++;
          for (int i = 0; i < (int)c.length(); ++i)
              T[2][c[i] - 'a']++;
          
          pair<int,int> best = make_pair(0, 0);
          
          for (int i = 0; ; ++i)
          {
              int other = getC(i);
              if (other == -1) break;
              
              best = max(best, make_pair(i + other, i));
          }
          
          int tc = best.first - best.second;
          int tb = best.second;
          
          for (int i = 0; i < tc; ++i)
              cout << c;
          for (int i = 0; i < tb; ++i)
              cout << b;
              
          for (int i = 0; i < 26; ++i)
          {
              T[0][i] -= tb * T[1][i] + tc * T[2][i];
              for (int j = 0; j < T[0][i]; ++j)
                  cout << (char)((int)'a' + i);
          }
          cout << endl;
          
          //wait;
          
          
          return 0;
}