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
ll a,b;
cin>>a>>b;
if (a==9)
{
if (b==1)
cout<<9<<" "<<10;
else
{
if (b==9)
cout<<901<<" "<<902;
else
cout<<-1;
}
}
else
{
    if (a+1==b)
    cout<<a<<" "<<b;
    else{
    if (a==b)
    cout<<10*a<<" "<<10*a+1;
    else
    cout<<-1;
    }
}
}