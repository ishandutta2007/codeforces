#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cmath>
#include <queue>
#define LD long double
#define LL long long
#define MP make_pair
#define ff first
#define ss second
#define PB push_back
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;

using namespace std;

int main()
{
  int x, y, x2, y2;
  scanf("%d%d%d%d",&x, &y, &x2, &y2);
  if(x == x2)
  {
    int d = y - y2;
    printf("%d %d %d %d", x2-d, y, x2-d, y2);
    return 0;    
  }
  if(y == y2)
  {
    int d = x - x2;
    printf("%d %d %d %d", x, y-d,  x2, y-d);
    return 0;
  }
  if(abs(x - x2) != abs(y - y2))
    printf("-1");
  else
  {
    if(x2 < x)
    {
      swap(x, x2);
      swap(y, y2);
    }
    printf("%d %d %d %d", x, y2, x2, y);
    return 0;     
      
  }
  return 0;
}