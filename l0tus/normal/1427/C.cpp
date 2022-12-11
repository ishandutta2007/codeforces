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

int dp[MN],x[MN],y[MN],t[MN];

int main()
{
   #ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
   #endif
   
    ios_base::sync_with_stdio(0),cin.tie(0);

   int R,N;
   cin >> R >> N;
   x[0] = y[0] = 1;
   for(int i=1; i<=N; i++){
      cin >> t[i] >> x[i] >> y[i];
   }
   int tmp = 0;
   for(int i=N; i>=0; i--){
      int res = 1;
      for(int j=i+1; j<=min(N,i+1000); j++)
         if(abs(x[j]-x[i])+abs(y[j]-y[i])<=t[j]-t[i]) res = max(res,dp[j]+1);
      dp[i] = max(res,tmp);
      if(i+1000<=N) tmp = max(tmp,dp[i+1000]+1);
   }
   cout << dp[0]-1;
}