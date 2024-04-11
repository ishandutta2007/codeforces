#include <bits/stdc++.h>
typedef long long ll;
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define vi vector <int>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll mod=1e9+7;

int main(){
mipletsplay;
int n,k;
cin>>n>>k;
vi a(n);
map <int,int> m;
for (int i=0;i<n;i++)
cin>>a[i];
for (int i=0;i<n;i++)
m[a[i]]++;
int maxik=-1;
for (auto to:m){
maxik=max(maxik,((to.second-1)/k+1)*k);
}
ll ans=0;
for (auto to:m)
ans+=maxik-to.second;
cout<<ans;
    
    
}