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
string s;
cin>>s;
string t="";
for (int i=0;i<s.size();i++)
{
if (s[i]!='a')
t.pb(s[i]);
}
string q="";
for (int i=0;i<t.size()/2;i++)
q+=t[i];
int j=0,i=0;
string f="";
bool ok=true;
while (j<=q.size() &&i<s.size())
{
if (s[i]==q[j] && j<q.size()){
f+=q[j];
i++;
j++;

}
else
{
if (s[i]=='a'){
f+='a';
i++;
}
else{
break;
}
}
}
string d=f+q;
if (ok && s==d&&t.size()>0)
cout<<f;
else{
int q=0;
for (int i=0;i<s.size();i++)
{
if (s[i]=='a')
q++;
}
if (q==s.size())
cout<<s;
else
cout<<":(";
}
}