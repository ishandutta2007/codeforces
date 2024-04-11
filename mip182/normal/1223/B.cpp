#include <bits/stdc++.h>
typedef long long ll;
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j)
#define pb push_back
#define pf push_front
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const ll MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
int q;
cin>>q;
for (int j=0;j<q;j++)
{
 string s,t;
 cin>>s>>t;
 vector <int> a(26),b(26);
 for (int i=0;i<s.size();i++)
 {
 a[s[i]-'a']++;
 b[t[i]-'a']++;
     
     
 }
 bool ok=false;
 for (int i=0;i<26;i++)
 {
 if (a[i]>0&&b[i]>0)
 ok=true;
 }
 if (ok)
 cout<<"YES";
 else
 cout<<"NO";
 cout<<endl;
    
    
    
    
}}