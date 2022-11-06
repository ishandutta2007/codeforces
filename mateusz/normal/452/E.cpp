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
#define MP make_pair
#define ff first
#define ss second
#define PB push_back
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;

using namespace std;

const int N = 300005;
const int P = 257;

class Mod
{
public:
  int w;
  const static int M = 1000000007;
  Mod (int _w = 0): w(_w%M) {}
  bool operator == (Mod const &B) const
  {
    return w == B.w;
  }
  bool operator != (Mod const &B) const
  {
    return w != B.w;
  }
  
  Mod operator + (Mod const &B) const
  {
    return (w + B.w)%M;
  }
  Mod operator - (Mod const &B) const
  {
    return ((w - B.w)+M)%M;
  }
  Mod operator * (Mod const &B) const
  {
    return (LL)w * B.w % M;
  }
  void operator += (Mod const &B)
  {
    *this = *this + B;
  }
  void operator *= (Mod const &B) 
  {
    *this = *this * B;
  }
  void operator -= (Mod const &B) 
  {
    *this = *this - B;
  }
};
Mod H[4][N];
Mod pot[N];
char s[4][N];
int n;
Mod ans[3*N];
Mod wynik;
int rep[3*N];
Mod ile[4][3*N];
pair<int, int>czas[3*N];
int czassize;
pair<int, int>tab[3*N];
int tabsize;
int find(int w)
{
  return rep[w] = (rep[w] == w? w: find(rep[w]));
}
void scal(int w, int u)
{
  int a = find(w);
  int b = find(u);
  wynik += ile[1][a] * ile[2][a] * ile[3][b] + ile[1][a] * ile[2][b] * (ile[3][a] + ile[3][b]) +  ile[1][b] * ile[2][b] * ile[3][a] + ile[1][b] * ile[2][a] * (ile[3][a] + ile[3][b]);
  ile[1][a] += ile[1][b];
  ile[2][a] += ile[2][b];
  ile[3][a] += ile[3][b];
  rep[b] = a;
}
int dl[4];
int potega[21];
int id[21][4][N];
int first_smaller[N];
bool cmp(pair<int, int> A, pair<int, int> B)
{
  int p1 = A.ff;
  int k1 = A.ss;
  int p2 = B.ff;
  int k2 = B.ss;
  int l = min(dl[k1] - p1 + 1, dl[k2] - p2 + 1);
//   int poc = 1;
//   int kon = l;
//   int ret = 0;
//   while(poc <= kon)
//   {
//     int sr = (poc + kon) / 2;
//     if(H[k1][p1 + sr - 1] - H[k1][p1 - 1] * pot[sr] == H[k2][p2 + sr - 1] - H[k2][p2 - 1] * pot[sr])
//     {
//       ret = sr;
//       poc = sr + 1;
//     }
//     else
//       kon = sr - 1;
//   }    
//   if(ret == l)
//     return dl[k1] - p1 < dl[k2] - p2;
//   
//   return s[k1][p1+ret] < s[k2][p2+ret];
  
  int FS = first_smaller[l];
  
  pair<int, int> id1 = MP(id[FS][k1][p1], id[FS][k1][p1 + l - potega[FS]]);
  pair<int, int> id2 = MP(id[FS][k2][p2], id[FS][k2][p2 + l - potega[FS]]);
  if(id1 != id2)return id1 < id2;
  return dl[k1] - p1 < dl[k2] - p2;
  
  
}
int LCP(int a, int b)
{
  int l = min(dl[tab[a].ss] - tab[a].ff + 1, dl[tab[b].ss] - tab[b].ff + 1);
  int poc = 1;
  int kon = l;
  int ret = 0;
  int k1 = tab[a].ss;
  int k2 = tab[b].ss;
  int p1 = tab[a].ff;
  int p2 = tab[b].ff;
  while(poc <= kon)
  {
    int sr = (poc + kon) / 2;
    if(H[k1][p1 + sr - 1] - H[k1][p1 - 1] * pot[sr] == H[k2][p2 + sr - 1] - H[k2][p2 - 1] * pot[sr])
    {
      ret = sr;
      poc = sr + 1;
    }
    else
      kon = sr - 1;
  }    
  return ret;
}


pair<pair<int, int>, pair<int, int> >S[3*N];
int Ssize;
void KMR()
{
  for(int i=1; i<=3; i++)
  {
    for(int j=1; j<=dl[i]; j++)
    {
      id[0][i][j] = s[i][j] - 96;
    }
  }
  int _id = 26;
  for(int k=1; k<=20; k++)
  {
    Ssize = 0;
    for(int i=1; i<=3; i++)
    {
      for(int j=1; j<=dl[i] - potega[k] + 1; j++)
      {
    S[++Ssize] = MP(MP(id[k-1][i][j], id[k-1][i][j+potega[k-1]]), MP(i, j));
      }
    }
    sort(S+1, S+1+Ssize);
    for(int i=1; i<=Ssize; i++)
    {
      if(S[i].ff != S[i-1].ff)
    _id++;
      id[k][S[i].ss.ff][S[i].ss.ss] = _id;      
    }
  }
  
}

int main()
{
  scanf("%s %s %s", &s[1][1], &s[2][1], &s[3][1]);
  int n1 = strlen(s[1]+1);
  int n2 = strlen(s[2]+1);
  int n3 = strlen(s[3]+1);
  potega[0] = 1;
  for(int i=1; i<=20; i++)potega[i] = potega[i-1] * 2;
  int akt = -1;
  for(int i=1; i<=max(n1, max(n2, n3)); i++)
  {
    if(potega[akt+1] == i)
      akt++;
    first_smaller[i] = akt;    
//     cout<<first_smaller[i]<<endl;
  }
  
  pot[0] = Mod(1);
  for(int i=1; i<=max(n1, max(n2, n3)); i++)
    pot[i] = pot[i-1] * Mod(P);
  
  dl[1] = n1;
  dl[2] = n2;
  dl[3] = n3;
  for(int i=1; i<=n1; i++)
  {
    H[1][i] = H[1][i-1] * Mod(P) + Mod(int(s[1][i] - 96));
    tab[++tabsize] = MP(i, 1);
  }
  for(int i=1; i<=n2; i++)
  {
    H[2][i] = H[2][i-1] * Mod(P) + Mod(int(s[2][i] - 96));
    tab[++tabsize] = MP(i, 2);
  }
  for(int i=1; i<=n3; i++)
  {
    H[3][i] = H[3][i-1] * Mod(P) + Mod(int(s[3][i] - 96));
    tab[++tabsize] = MP(i, 3);
  }  
  KMR();
  sort(tab+1, tab+1+tabsize, cmp);
  for(int i=2; i<=tabsize; i++)
    czas[++czassize] = MP(LCP(i, i-1), i);
  for(int i=1; i<=tabsize; i++)
  {
    rep[i] = i;
    ile[tab[i].ss][i] = Mod(1);
  }
  sort(czas+1, czas+1+czassize);
  
  int wsk = min(n1, min(n2, n3));
  
  for(int i=wsk; i>=1; i--)
  {
    while(czassize >= 1 && czas[czassize].ff  >= i)
    {
      int w = czas[czassize].ss;
      scal(w, w-1);
      czassize--;
    }
    ans[i] = wynik;
  }
  
  for(int i=1; i<=wsk; i++)
    printf("%d ", ans[i].w);
  
  return 0;
}