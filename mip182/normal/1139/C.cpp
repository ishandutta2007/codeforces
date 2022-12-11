#include <bits/stdc++.h>
typedef long long ll;
#define vstroku() to_string()
#define vchislo() to_ulong()
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back 
#define F first
#define S second
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const int MAXN = 3e5;
const int INF = 1e9;
const int kek=998244353;
const int mod=1e9+7;

ll n,k,sum=0;
vector <bool> pos(1e5);
vector <vector <int>> g(1e5);

int pow(ll r)
{
ll u=1;
for (int i=0;i<k;i++)
{
    
u=(u*r)%mod;

}
return u;    
    
}
void bfs(int s)
{
 queue <int> q;
 int ans=0;
 ans++;
 pos[s]=1;
 q.push(s);
 while (q.size()>0)
 {
  int t=q.front();
  q.pop();
  for (int i=0;i<g[t].size();i++)
  {
    if (pos[g[t][i]]!=1)
    {
    ans++;
    pos[g[t][i]]=1;
    q.push(g[t][i]);
        
    }
     
      
      
  }
     
     
     
 }
 sum+=pow(ans);
// cout<<s<<" "<<ans<<endl;
 sum=(sum%mod);
    
}

int main() {
mipletsplay;
cin>>n>>k;
//g=vector < vector <int> > (n);
//pos=vector <bool> (n);
for (int i=0;i<n-1;i++)
{
 int x,y,z;
 cin>>x>>y>>z;
 if (z==0){
 g[x-1].pb(y-1);
 g[y-1].pb(x-1);
 }
    
}
for (int i=0;i<n;i++)
{
 if (pos[i]==0)
 bfs(i);
    
    
    
}
sum=(((pow(n)-sum)%mod)+mod)%mod;
cout<<sum;
}