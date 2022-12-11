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
int t;
cin>>t;
rep(jj,t)
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=INF,b=-1;
    ll ans=n;
    rep(i,n)
    {
    if (s[i]=='1')
    {
    a=min(a,i);
    b=max(b,i);
    }
    }
    if (b==-1)
    cout<<n<<endl;
    else{
    int f=a+2+a;
    int q=a+2+n-a-1;
    int u=n-a-1+2+n-1-a;
    int y=n-a-1+2+a;
    cout<<max(max(max(f,q),max(u,y)),max(max(b+2+b,b+2+n-b-1),max(n-b-1+2+n-1-b,n-b-1+2+b)))<<endl;
        
    
    }
    }
}