#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
	bool ok=true;
	int st;
cin>>st;
st*=2;

	int x;cin>>x;
	cin>>x;
	if(st==0&&x)ok=false;
	cin>>x;
	st-=x*2;
	if(st!=0)ok=false;
if(ok)cout<<1<<endl;
else cout<<0<<endl;

    return 0;
}