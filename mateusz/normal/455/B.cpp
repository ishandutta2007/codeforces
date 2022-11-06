#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define LL long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define DEBUG(lol) cerr<<#lol<<" "<<(lol)<<endl;
using namespace std;
const int N = 100005;
string s[N];
int n, m;
int l[N];
const LL P = 257;
const LL M = 1000000007;
vector<LL>H[N];
priority_queue<pair<int, int> >Q, Q2;
map<LL, int>Wygr, Przegr;
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
  {
    cin>>s[i];
    s[i] = char(96)+s[i];
    l[i] = s[i].length();
    H[i].PB(0);
    for(int j=1; j<l[i]; j++)
    {
      H[i].PB((H[i][j-1] * P + s[i][j] - 96)%M);      
      Q.push(MP(j, i));
   
      Q2.push(MP(j, i));
    }
    H[i].PB((H[i][l[i]-1]*P+int('#')-96)%M);
    Q2.push(MP(l[i], i));
  }
  while(!Q.empty())
  {
    int poz = Q.top().ff;
    int w = Q.top().ss;
    Q.pop();
    LL Hasz = H[w][poz];
    if(!Przegr.count(Hasz))
    {
      Przegr[H[w][poz-1]] = 1;
    }
  }
  int wygr = 0;
  for(int i=1; i<=n; i++)
  if(!Przegr.count(H[i][1]))
    wygr = 1;
  
  while(!Q2.empty())
  {
    int poz = Q2.top().ff;
    int w = Q2.top().ss;
    Q2.pop();
    LL Hasz = H[w][poz];
    if(!Wygr.count(Hasz))
    {
      Wygr[H[w][poz-1]] = 1;
    }
  }
  int przegr = 0;
  for(int i=1; i<=n; i++)
  if(!Wygr.count(H[i][1]))
  {
    przegr = 1;
    break;
  }
  if(wygr && przegr)
  {
    if(m % 2 == 0)
      printf("First");
    else
      printf("Second");
  }
  if(wygr && !przegr)
  {
    if(m % 2 == 0)
      printf("Second");
    else
      printf("First");
  }
  if(!wygr)
    printf("Second");
  
  return 0;
    
  
}