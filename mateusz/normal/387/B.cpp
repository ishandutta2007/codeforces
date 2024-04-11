#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define LL long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define DEBUG(x) cout<<#x<<" "<<(x)<<endl;
#define INF 1000000000
#define MAX_N 1000005
using namespace std;
int n,m,tab1[3005],tab2[3005],wynik;

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&tab1[i]);
  }
  for(int i=1;i<=m;i++)
  {
    scanf("%d",&tab2[i]);
  }
  
  int in=m;
  
  for(int i=n;i>=1;i--)
  {
    if(tab2[in]>=tab1[i])
    {
      in--;      
    }
    else
    {
      wynik++;      
    }
  }
  printf("%d",wynik);
  return 0;
}