#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
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
const int N = 100005;
const LL INF = 1e9;
int n;
int connected[N];
int sito[N];
pair<int, int>S[N];
int size;
bool odw[N];
priority_queue<pair<int, int> >niepolaczone;
set<int>V[N];
int NWD(int a, int b)
{
  if(b == 0)return a;
  return NWD(b, a%b);
}
// vector<int>V[N];
void dodaj(int w)
{
  int temp = w; 
  int a =temp;
  while(w > 1)
  {
    int s = sito[w];
//     cout<<"Elo\n";
    
    if(!V[s].count(a))
    {
      V[s].insert(a);
    }
    w /= s;
  }
  niepolaczone.push(MP(-sito[temp], temp));
}
void usun(int w)
{
  int a = w;
//   DEBUG("5");
  while(w > 1)
  {
//     cout<<"elo\n";
    int s = sito[w];
    if(V[s].find(a) != V[s].end())
    V[s].erase(V[s].lower_bound(a));
    w /= s;
  }
}
bool sprobuj(int w)
{
  
  int a = w;
  while(w > 1)
  {
    int s = sito[w];
//     DEBUG(w);
    if(!V[s].empty())
    {
//       cout<<"elo\n";
      set<int>::iterator it = V[s].end();
      it--;
      int u = *it;
   
      connected[a] = u;
      connected[u] = a;
      usun(u);
      return 1;
    }
    w /= s;
  }
//   cout<<"git\n";
  return 0;
}

int main()
{
//   list<int>::iterator it = L[0].lower_bound(5);
  ios_base::sync_with_stdio(0);
  cin>>n;
  
  for(int i=2; i<=n; i++)
  {
    if(sito[i] == 0)
    {
      sito[i] = i;
      for(int j=2*i; j<=n; j += i)
      {
    if(sito[j] == 0)sito[j] = i;
      }
    }
  }

  for(int i=2; i<=n; i++)
  {
//     DEBUG(i);
//     for(int j=0; j<niepolaczone.size(); j++)
//     {
//       cout<<niepolaczone[j]<<" ";
//     }
//     cout<<endl;
//     LL mini = INF;
//     int ktory = 0;
//     int tak = 0;
//     cout<<i<<" "<<niepolaczone.size()<<endl;
//     cout<<"elo\n";
    if(sprobuj(i)){/*cout<<i<<" "<<connected[i]<<endl;*/continue;}
//     cout<<"Elo\n";
    int u;
    while(!niepolaczone.empty() && connected[niepolaczone.top().ss])niepolaczone.pop();
    if(!niepolaczone.empty())
    {
      u = niepolaczone.top().ss;
      niepolaczone.pop();
    }
    else
    {  
      dodaj(i);
      continue;
    }
//     DEBUG(u);
    
      LL P = (LL)sito[u]*sito[i];
//       DEBUG(P);
      if(P > i)
      {
    niepolaczone.push(MP(-sito[u], u));
    dodaj(i);
    continue;
      }
      else
      {
    usun(u);
//  DEBUG("git");
    int R = connected[P];
//  cout<<u<<" "<<P<<" "<<R<<endl;
    if(NWD(R,u) > 1)
    {
      connected[u] = R;
      connected[R] = u;
      connected[i] = P;
      connected[P] = i;
    }
    else
    {
      connected[i] = R;
      connected[R] = i;
      connected[u] = P;
      connected[P] = u;
    }
      }
//     cout<<i<<" "<<connected[i]<<endl;
  }
  for(int i=2; i<=n; i++)
  {
    if(connected[i] > i)
      S[++size] = MP(i, connected[i]);
  }
  printf("%d\n", size);
  for(int i=1; i<=size; i++)
  {
    printf("%d %d\n", S[i].ff, S[i].ss);
  }
  return 0;
}