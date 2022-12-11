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
string s;
cin>>s;
pii a={0,-1};
int i=0;
while (i<n&&a.first<=(n-11)/2)
{
if (s[i]=='8')
a={a.first+1,i};
i++;
}
//cout<<a.first<<" "<<a.second<<endl;
if (a.first<=(n-11)/2)
cout<<"NO";
else
{
if (a.second<=n-11)
cout<<"YES";
else
cout<<"NO";
}}