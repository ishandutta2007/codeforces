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
#define double long double
#define MP make_pair
#define ff first
#define ss second
#define PB push_back
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int a, b;
  cin>>a>>b;
  cout<<((min(a, b)%2)?"Akshat":"Malvika");
  return 0;
}