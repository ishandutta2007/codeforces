#include <bits/stdc++.h>
typedef long long ll;
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define eb emplace_back 
#define MP make_pair 
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 
#define REP(i, a, b) for (int i = a; i < b; i++)


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const int INF = 1e9;

int main() {
mipletsplay;
int n;
cin >> n;
vector <ll> b;
vector <pair<ll,ll>> a(n-1);
ll sizea,sum=0,answer;
cin >> sizea;
answer=sizea;
sum+=sizea;
for (int i=0;i<n-1;i++){
cin >> a[i].first;
sum+=a[i].first;
a[i].second=i+2;
}
sort(a.begin(),a.end());
int j=0;
while (a[j].first<=sizea/2 && j<=n-2)
{
 answer+=a[j].first;
 b.pb(a[j].second);
 j++;
}
if (answer>sum/2)
{
 cout << b.size()+1<<endl;
 cout << 1<<" ";
 for (int i=0;i<b.size();i++)
 cout << b[i]<<" ";
    
    
}
else
cout << 0;}