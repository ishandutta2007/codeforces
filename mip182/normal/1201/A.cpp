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
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;

int n,m;
cin>>n>>m;
ll a[m+1][10];
for (int i=0;i<m;i++)
{
 for (int j=0;j<10;j++)
 a[i][j]=0;
    
}
vector <ll> b(m);
for (int i=0;i<n;i++)
{
string s;
cin>>s;
for (int j=0;j<m;j++){
a[j][s[j]-'A']++;
// cout<<s[j]-'A'<<endl;
}
}
for (int i=0;i<m;i++)
cin>>b[i];
ll ans=0;
for (int i=0;i<m;i++)
{
ll maxim=0;
for (int j=0;j<10;j++)
maxim=max(maxim,a[i][j]);
ans+=b[i]*maxim;
}
cout<< ans;}