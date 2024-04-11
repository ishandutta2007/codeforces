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
 
string s;
cin>>s;
ll cnt=0,pos1=-1,pos2=-1;
bool ok1=false,ok2=false,ok3=false,ok4=false;
for (int i=0;i<s.size();i++)
{
if (s[i]=='[')
ok1=true;
if (s[i]==':' && ok1){
ok2=true;
if (pos1==-1)
pos1=i;
}
if (s[s.size()-1-i]==']')
ok4=true;
if (ok4 && s[s.size()-1-i]==':')
{
ok3=true;
if (pos2==-1)
pos2=s.size()-1-i;
}
}
if (pos1>=0 && pos2>=0 && pos1<pos2)
{
for (int i=pos1+1;i<pos2;i++)
{
if (s[i]=='|')
cnt++;
}
cout<<4+cnt;

}
else
cout<<-1;
}