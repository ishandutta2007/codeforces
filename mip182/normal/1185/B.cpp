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


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
int n;
cin>>n;
rep(jj,n)
{
string a,b;
cin>>a>>b;
int i=0,j=0;
vector <pair<char,int> > c;
while (i<a.size())
{
int cnt=0;
while (j<a.size()&&a[i]==a[j]){
j++;
cnt++;
}
c.pb({a[i],cnt});
i=j;
}
vector <pair <char,int> > d=c;
c.clear();
i=0,j=0;
while (i<b.size())
{
    int cnt=0;
while (j<b.size()&&b[i]==b[j]){
j++;
cnt++;
}
c.pb({b[i],cnt});
i=j;
}
bool ok=true;
for (int i=0;i<d.size();i++)
{
if (d[i].first!=c[i].first||d[i].second>c[i].second)
ok=false;
}
if (d.size()!=c.size())
ok=false;
if (ok)
cout<<"YES";
else
cout<<"NO";
cout<<endl;

    
    
}}