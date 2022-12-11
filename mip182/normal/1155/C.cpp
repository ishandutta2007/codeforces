#include <bits/stdc++.h>
typedef long long ll;
#define vstroku() to_string()
#define vchislo() to_ulong()
//#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back 
#define pii pair <int, int>
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
vector <ll> x(n);
for (int i=0;i<n;i++)
cin>>x[i];
vector <ll> p(m);
for (int i=0;i<m;i++)
cin>>p[i];
sort (x.begin(),x.end());
ll y=x[0];
ll q=0;
for (int i=0;i<n-1;i++)
q=gcd(q,x[i+1]-x[i]);
ll h=-1;
for (int i=0;i<m;i++)
{
if (q%p[i]==0)
h=i;
}
if (h!=-1)
{
cout<<"YES"<<endl;
cout<<y<<" "<<h+1;
}
else
cout<<"NO";}