#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#define LL long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<endl;

using namespace std;

LL l, r, k;
int main()
{
  srand(151351);
  ios_base::sync_with_stdio(0);
  cin>>l>>r>>k;
  if(k == 1 || l == r)
    cout<<l<<"\n"<<1<<"\n"<<l;
  else
  {
    LL x=l, y=r;
    if((x ^ y) <= l || (x ^ y) >= r) {
      y--;
    if((x ^ y) <= l || (x ^ y) >= r) {
    for(int i=1; i<=10000; i++){
    y = l + (((LL)rand()* rand() * rand() * rand())%(r - l + 1));
    x = l + (((LL)rand() * rand())%(x - l + 1));
    if((x ^ y) >= l && (x ^ y) <= r && x != (x ^ y) && y != (x ^ y))
      break;
    }
    }
    }
    if((k > 2 && ((x ^ y) >= l && (x ^ y) <= r && x != (x ^ y) && y != (x ^ y))))
    {

    cout<<0<<"\n"<<3<<"\n"<<x<<" "<<y<<" "<<(x ^ y);
    }
    else if((k >= 4 && r - l + 1 >= 4 &&((((l ^ (l + 1)) ^ (l + 2)) ^ (l + 3))) == 0))
    {
      cout<<0<<"\n"<<4<<"\n"<<l<<" "<<l + 1<<" "<<l + 2<<" "<<l + 3;
    }
    else if(k >= 4 && r - l + 1 >= 5)
    {
      cout<<0<<"\n"<<4<<"\n"<<l + 1<<" "<<l + 2<<" "<<l + 3<<" "<<l + 4;
    }
    else
    {
      LL wynik = (l ^ (l + 1));
      if(r - l + 1 > 2 && ((l + 1) ^ (l + 2)) < wynik)
      {
    cout<<((l + 1) ^ (l + 2))<<"\n"<<2<<"\n"<<l + 1<<" "<<l + 2;      
      }
      else
      {
    if(l < wynik)
    {
      cout<<l<<"\n"<<1<<"\n"<<l;
    }
    else
    cout<<wynik<<"\n"<<2<<"\n"<<l<<" "<<l + 1;
      }
    
    }

  }

  return 0;
}