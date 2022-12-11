#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 1e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int N,A[100],B[100],sz[100];
bool ch[100];

vector<int> ans[100];

int pos(int x)
{
   for(int j=1; j<=N; j++){
      if(A[j]==x) return j;
   }   
}

void solve(int t)
{
   //for(int i=1; i<=N; i++) cout << A[i] << ' ';
   //cout << '\n';
   int a=0,b=0;
   bool end = 1;
   for(int i=1; i<=N; i++){
      if(ch[i]) continue;
      a = b;
      b = i;
      if(a==0) continue;
      int x = pos(a), y = pos(b);
      if(x<y) continue;
      if(y-1) ans[t].push_back(y-1);
      if(x-y) ans[t].push_back(x-y);
      ans[t].push_back(sz[a]);
      if(N-x+1-sz[a]) ans[t].push_back(N-x+1-sz[a]);
      for(int i=1; i<=N-x+1-sz[a]; i++) B[i] = A[x+sz[a]-1+i];
      for(int i=1; i<=sz[a]; i++) B[N-x+1-sz[a]+i] = A[x-1+i];
      for(int i=1; i<=x-y; i++) B[N-x+1+i] = A[y-1+i];
      for(int i=1; i<=y-1; i++) B[N-y+1+i] = A[i];
      for(int i=1; i<=N; i++) A[i] = B[i];
      end = 0;
      ch[b] = 1;
      sz[a] += sz[b];
      break;
   }

   if(end){
      cout << N-t << '\n';
      for(int i=N; i>t; i--){
         cout << ans[i].size() << ' ';
         for(int x:ans[i]) cout << x << ' ';
         cout << '\n';
      }
      return;
   }
   solve(t-1);
}

int main()
{
   #ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
   #endif
   
   ios_base::sync_with_stdio(0),cin.tie(0);
   
   cin >> N;
   for(int i=1; i<=N; i++){
      cin >> A[i];
      sz[i] = 1;
   }
   solve(N);  
}