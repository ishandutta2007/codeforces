#include <iostream>
#include <map>
#include <cmath>
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
const int S = 350;
int ile[S][N];
int tab[N];
int  n;
int L, P;
queue<int>Q[S];
void insert(int a, int b)
{
  int kp = a/P + 1;
  if(a % P == 0)kp--;
  int kk = b/P + 1;
  if(b % P == 0)kk--;
  if(kp == kk)
  {
    vector<int>v;
    while(!Q[kp].empty())
    {
      v.PB(Q[kp].front());
      Q[kp].pop();
    }
    reverse(v.begin(), v.end());
    int poc = (kp-1)*P+1;
    int kon = kp*P;
    for(int i=v.size()-1; poc+i > b; i--)
    {
      Q[kp].push(v[i]);
    }
    int x = v[b-poc];
    for(int i=b-poc-1; i >= 0; i--)
    {
      
      Q[kp].push(v[i]);
      if(poc+i == a)
      Q[kp].push(x);
    }

  }
  else
  {
    int last = Q[kp].front();
    ile[kp][last]--;
    Q[kp].pop();
    for(int i=kp+1; i<kk; i++)
    {
      Q[i].push(last);
      ile[i][last]++;
      last = Q[i].front();
      ile[i][last]--;
      Q[i].pop();
    }
    vector<int>v;
    while(!Q[kk].empty())
    {
      v.PB(Q[kk].front());
      Q[kk].pop();
    }
    reverse(v.begin(), v.end());
    int pam = 0;
    for(int i=v.size()-1; i>=0; i--)
    {
      if(i+(kk-1)*P+1 == b)
      {
    pam = v[i];
      }
      else
      {
    Q[kk].push(v[i]);
      }
    }
    ile[kk][pam]--;
    Q[kk].push(last);
    ile[kk][last]++;
    vector<int>v2;
    while(!Q[kp].empty())
    {
      v2.PB(Q[kp].front());
      Q[kp].pop();
    }
    reverse(v2.begin(), v2.end());
    for(int i=v2.size()-1; i>=0; i--)
    {
      if(i + (kp-1)*P+2 == a)
      {
    Q[kp].push(pam);
    ile[kp][pam]++;
      }
      Q[kp].push(v2[i]);


    }
    if((kp-1)*P+1 == a)
      {
    Q[kp].push(pam);
    ile[kp][pam]++;
      }
  }
}

int query(int a, int b, int k)
{
  int ret = 0;
  int kp = a/P + 1;
  if(a % P == 0)kp--;
  int kk = b/P + 1;
  if(b % P == 0)kk--;
  if(kp == kk)
  {
    vector<int>v;
    while(!Q[kp].empty()){
      v.PB(Q[kp].front());
      Q[kp].pop();
    }
    reverse(v.begin(), v.end());
    for(int i=v.size() - 1; i>=0; i--)
    {
      if(i + (kp-1)*P+1 >= a && i+(kp-1)*P+1 <= b && v[i] == k)ret++;
      Q[kp].push(v[i]);
    }
    
  }
  else
  {
    for(int i=kp+1; i<kk; i++)
      ret += ile[i][k];
    
    vector<int>v;
    while(!Q[kp].empty())
    {
      v.PB(Q[kp].front());
      Q[kp].pop();
    }
    reverse(v.begin(), v.end());
    for(int i=v.size()-1; i>=0; i--)
    {
      if(i + (kp-1)*P+1 >= a && v[i] == k)ret++;
      Q[kp].push(v[i]);
    }
    v.clear();
    while(!Q[kk].empty())
    {
      v.PB(Q[kk].front());
      Q[kk].pop();
    }
    reverse(v.begin(), v.end());
    for(int i=v.size()-1; i>=0; i--)
    {
      if(i + (kk-1)*P+1 <= b && v[i] == k)ret++;
      Q[kk].push(v[i]);
    }
  }
  return ret;
}

int main()
{
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d", &tab[i]);
  }
  
  P = sqrt(n);
  L = n/P;
  if(n%P != 0)L++;
  for(int i=1; i<=L; i++)
  {
    int pp = (i-1)*P+1;
    int kp = min(n, i*P);
    for(int j=kp; j>=pp; j--)
    {
      Q[i].push(tab[j]);
      ile[i][tab[j]]++;
    }
  }
  int q, a, b, co, k;
  scanf("%d", &q);
  int lastans = 0;
  while(q--)
  {
    int co;
    scanf("%d", &co);
    if(co == 1)
    {
      scanf("%d%d", &a, &b);
      a = ((a + lastans - 1)%n)+1;
      b = ((b+lastans-1)%n)+1;
      if(a > b)swap(a, b);
        if(a == b)continue;
      insert(a, b);
    }
    else
    {
      scanf("%d%d%d", &a, &b, &k);
      
      a = ((a + lastans - 1)%n)+1;
      b = ((b + lastans - 1)%n)+1;
      k = ((k + lastans - 1)%n)+1;
      if(a > b)swap(a, b);
      printf("%d\n", lastans = query(a, b, k));
    }
  }
  
  
}