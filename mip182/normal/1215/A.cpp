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
int a1,a2,k1,k2;
cin>>a1>>a2>>k1>>k2;
if (k1<k2){
swap(k1,k2);
swap(a1,a2);
}
int n;
cin>>n;
cout<<max(0,n-(k1-1)*a1-a2*(k2-1))<<" ";
cout<<min(n/k2,a2)+(n-min(n/k2,a2)*k2)/k1;}