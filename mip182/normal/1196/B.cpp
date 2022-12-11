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
#define F first
#define S second
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const int INF = 1e9;
const long long kek=998244353;

int main() {
mipletsplay;

int q;
cin>>q;
for (int i=0;i<q;i++)
{
int n,k;
cin>>n>>k;
int answer=0;
vector<int> a(n);
for (int j=0;j<n;j++)
{
    cin>> a[j];
    
 if (a[j]%2==1)
 answer++;
    
}
int f=answer%2;
int d=k%2;
if (answer>=k && f==d){
cout<<"YES"<<endl;
int h=0;
while (k>1)
{

if (a[h]%2==1){
cout << h+1<<" ";
k--;
}
h++;
}
cout << n<<endl;
}
else
cout<<"NO"<<endl;
    
    
    
}}