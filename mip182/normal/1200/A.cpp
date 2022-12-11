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

int n;
cin>>n;
string s;
cin>>s;
vector <int> a(10,0);
for (int i=0;i<n;i++)
{
if (s[i]=='L'){
    for (int j=0;j<=9;j++)
if (a[j]==0){
a[j]=1;
break;
}}
else{
if (s[i]=='R'){
for (int j=0;j<=9;j++)
if (a[9-j]==0){
a[9-j]=1;
break;
}}
else
{
int h=s[i]-'0';
a[h]=0;
    
    
    
}}}
for (int i=0;i<=9;i++)
cout<<a[i];
    
    
}