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
int i=0,j=0;
vector <int> b(26,0);
while (i<s.size())
{
int cnt=0;
while (j<s.size()&&s[i]==s[j])
{
cnt++;
j++;
}
if (cnt%2==1)
b[s[i]-'a']=1;
i=j;
}

for (int k=0;k<26;k++)
{
if (b[k]==1){
string c="";
c+='a'+k;
cout<<c;
}
}
cout<<endl;
    
}}