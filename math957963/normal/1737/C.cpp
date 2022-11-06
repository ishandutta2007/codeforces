#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD 998244353
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
  int t,n;
  int a,b,c,d,e,f,g,h;
  int x,y;
  cin>>t;
  rep(tt,t){
    cin>>n;
    cin>>a>>b>>c>>d>>e>>f;
    cin>>g>>h;
    if(a==c)x=a;
    else if(a==e)x=a;
    else x=c;
    if(b==d)y=b;
    else if(b==f)y=b;
    else y=d;
    if(((x==1)||(x==n))&&((y==1)||(y==n))){
      if((g==x)||(h==y))cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    else{
      if(((g%2)==(a%2))&&((h%2)==(b%2)))cout<<"YES"<<endl;
      else if(((g%2)==(c%2))&&((h%2)==(d%2)))cout<<"YES"<<endl;
      else if(((g%2)==(e%2))&&((h%2)==(f%2)))cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }

    
	return 0;
}