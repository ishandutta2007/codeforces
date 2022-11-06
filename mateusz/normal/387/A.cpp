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
string s1,s2;

int main()
{
  cin>>s1;
  cin>>s2;
  for(int i=0;i<s1.size();i++)
  {
    s1[i]-=48;
    s2[i]-=48;
  }
  int h1=s1[0]*10+s1[1];
  int h2=s2[0]*10+s2[1];
  
  int m1=s1[3]*10+s1[4];
  int m2=s2[3]*10+s2[4];

  
  int h=h1-h2;
  if(h<0)h+=24;
  int m=m1-m2;
  if(m<0)
  {
    h--;
    if(h<0)h+=24;
    m+=60;
  }
  if(h<10)
    cout<<0;
  cout<<h;
  cout<<":";
  if(m<10)
    cout<<0;
  cout<<m;
  return 0;
}