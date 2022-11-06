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
#define check if(nr <= n-k && nr2 <= k && (k-nr2)%3 == 0 && !((n-k-nr)%3)){cout<<"yes\n"; continue;}
using namespace std;
int p_count[2], np_count[2];
int main()
{
  ios_base::sync_with_stdio(0);
  string word;
  cin>>word;
  LL ans1 = 0, ans2 = 0;
  for(int i=0; i<word.size(); i++)
  {
    int w = word[i] - 97;
    if(i % 2)
    {
      ans1 += p_count[w];
      np_count[w]++;
      ans2 += np_count[w];
    }
    else
    {
      ans1 += np_count[w];
      p_count[w]++;
      ans2 += p_count[w];
    }
  }
  cout<<ans1<<" "<<ans2;
  return 0;
}