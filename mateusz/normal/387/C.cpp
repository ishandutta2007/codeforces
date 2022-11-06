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
string S[100005];
int size;
string s;
bool comp(string a, string b)
{
    if(a.size()>b.size())return 1;
    if(a.size()<b.size())return 0;
  for(int i=0;i<min(a.size(),b.size());i++)
  {
    if(a[i]>=b[i])return 1;
    if(a[i]<b[i])return 0;
  }

  return 1;
}

int main()
{
  cin>>s;
  
  for(int i=s.size()-1;i>=0;i--)
  {
    string x;
    x.clear();
      while(s[i]=='0')
      {
    x=x+"0";
    i--;
      }
      x=s[i]+x;
//       cout<<x<<endl;
      S[++size]=x;
    
  }
  s.clear();
//   int i=size;
//   int j=size-1;
  int wynik=1;
  for(int i=size;i>=2;i--)
  {
    string x=S[i];
    string y=S[i-1];
//     cout<<x<<endl;
    if(comp(x,y)==1)
    {
      wynik++;
    }
    else
      wynik=1;
    S[i-1]=x+y;
    S[i].clear();
    
  }
  printf("%d",wynik);
  return 0;
  
}