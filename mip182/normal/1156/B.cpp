#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define pf push_front
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define sz(x) (int)x.size()

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
int t;
cin>>t;
rep(jj,t)
{
string s;
cin>>s;
string a="",b="";
for (int i=0;i<s.size();i++)
{
if ((s[i]-'a')%2==0)
a+=s[i];
else
b+=s[i];
}
sort(all(a));
sort(all(b));
string c=a+b,d=b+a;
bool ok=true;
for (int i=0;i<c.size()-1;i++)
{
if (abs(c[i]-c[i+1])==1)
ok=false;
}
if (ok)
{
cout<<c<<endl;
continue;
}
ok=true;
for (int i=0;i<d.size()-1;i++)
{
if (abs(d[i]-d[i+1])==1)
ok=false;
}
if (ok)
cout<<d<<endl;
else
cout<<"No answer"<<endl;

    
    
    
}}