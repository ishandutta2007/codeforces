#include <bits/stdc++.h>
typedef long long ll;
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define vi vector <int>
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
int q;
cin>>q;
set <int> strings[26];
for (int i=0;i<s.size();i++)
{
strings[s[i]-'a'].insert(i);
}
for (int jj=0;jj<q;jj++)
{
int a;
cin>>a;
if (a==1)
{
int b;
char c;
cin>>b>>c;
b--;
strings[s[b]-'a'].erase(b);
strings[c-'a'].insert(b);
s[b]=c;
}
else
{
int b,c;
cin>>b>>c;
b--;
c--;
int cnt=0;
for (int i=0;i<26;i++)
{
auto k=strings[i].lower_bound(b);
if (k!=strings[i].end()&& (*k)<=c)
cnt++;
}
cout<<cnt<<endl;
}

}}