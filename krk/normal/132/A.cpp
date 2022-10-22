#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 256;

int Rev(int x)
{
    int rnum = 0;
    for (int i = 0; i < 8; i++)
       rnum |= ((x & (1 << i)) >> i) << (7 - i);
    return rnum;
}

int main()
{
    char c;
    int res = 0;
    while (scanf("%c", &c) == 1) {
          if (c < 32 || c > 126) break;
          int num = res - Rev(int(c));
          if (num < 0) num += mod;
          cout << num << endl;
          res = Rev(int(c));
    }
    return 0;
}