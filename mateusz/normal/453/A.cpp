#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define double long double
#define LL long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define DEBUG(lol) cout<<#lol<<" "<<(lol)<<endl;
using namespace std;

double potega(double w, int k)
{
  if(k == 0)
    return 1;
  if(k == 1)return w;
  if(k % 2 == 0)
    return potega(w, k/2) * potega(w, k/2);
  else
    return potega(w, k/2) * potega(w, k/2) * w;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin>>n>>m;
  double wynik = n;
  for(int i=n-1; i>=1; i--)
    wynik -= potega( (double) i/(double)n, m);
  cout<<wynik;
  return 0;
}