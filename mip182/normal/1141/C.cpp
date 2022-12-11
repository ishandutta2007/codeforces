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
int n;
cin>>n;
vector <int> p(n-1);
vector <int> a(n);
for (int i=0;i<n-1;i++)
{
    cin>>p[i];
}
a[0]=n;
for (int i=0;i<n-1;i++)
{
a[i+1]=p[i]+a[i];
}
int c=INF,b=INF;
for (int i=0;i<n;i++)
{
if (c>a[i])
{
c=a[i];
b=i;
}
}
for (int i=0;i<n;i++)
a[i]-=c-1;
map <int,int> m;
bool ok=true;
for (int i=0;i<n;i++)
{
m[a[i]]++;
if (a[i]<1||a[i]>n||m[a[i]]!=1)
ok=false;
}
if (ok)
{
for (int i=0;i<n;i++)
cout<<a[i]<<" ";
}
else
cout<<-1;}