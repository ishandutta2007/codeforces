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
bool comp ( pair <int,int> a, pair <int,int> b)
{
    return a.first + a.second < b.first + b.second;
}

int main() {
mipletsplay;
int n;
cin>>n;
int r;
cin>>r;
vector <pair <int, int> > pos,neg;
for (int i=0;i<n;i++)
{
int a,b;
cin>>a>>b;
if (b>=0)
pos.pb({a,b});
else
neg.pb({a,b});
}
string ans="YES";
sort(pos.begin(),pos.end());
sort(neg.begin(),neg.end(),comp);
for (int i=0;i<pos.size();i++)
{
if (r>=pos[i].first)
r+=pos[i].second;
else
ans="NO";
}
for (int i=neg.size()-1;i>=0;i--)
{
if (r>=neg[i].first)
r+=neg[i].second;
else
ans="NO";
if (r<0)
ans="NO";
}
cout<<ans;
}