#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#define LL long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<endl;

using namespace std;
int n, m;
int main()
{
  scanf("%d%d", &n, &m);
  int days = 1;
  while(n)
  {
    n--;
    if(days % m == 0)
      n++;
    days++;
  }
  printf("%d", days - 1);
  return 0;
}