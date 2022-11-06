#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll a[1000],s[1000];
int main() {
	ios_base::sync_with_stdio(false);
	string st;
	getline(cin,st);
	ll slen=st.length();
	vector<ll> op;
	ll add=1,sub=0;
	ll n=-1;
	for (ll i=0;i<slen;i++) {
		if (st[i]=='+') {
			add++;
			op.PB(1);
		}
		else if (st[i]=='-') {
			sub++;
			op.PB(-1);
		}
		else if (st[i]=='=') {
			stringstream ss(st.substr(i+2,slen-i));
			ss>>n;
			break;
		}
	}

	assert(n!=-1);
	ll sum=add-sub;
	for (ll i=0;i<add;i++) a[i]=1;
	for (ll i=0;i<sub;i++) s[i]=1;
	for (ll i=0;i<add;i++) {
		ll go=max(0LL,min(n-sum,n-a[i]));
		a[i]+=go; sum+=go;
	}
	for (ll i=0;i<sub;i++) {
		ll go=max(0LL,min(sum-n,n-a[i]));
		s[i]+=go; sum-=go;
	}
	if (sum==n) {
		cout<<"Possible"<<endl;
		cout<<a[0]<<" ";
		ll ai=1,si=0;
		for (auto &o:op) {
			if (o==1) {
				cout<<"+ "<<a[ai]<<" ";
				ai++;
			}
			else {
				cout<<"- "<<s[si]<<" ";
				si++;
			}
		}
		cout<<"= "<<n<<endl;
	}
	else {
		cout<<"Impossible"<<endl;
	}

}