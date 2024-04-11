#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 7;
const int INF = 1e9;

int n;
int a[N];
vector<int> vl;
int lcm1 = 1,lcm2 = 1;
int mx = 0;

int lcm(int a,int b) {
	return (a * b) / __gcd(a,b);
}
signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> a[i];
	for(int i = 2;i <= n;++i) {
	 vl.push_back(abs(a[i] - a[i - 1]));
	 if(vl.back() == 0) return cout << "NO\n",0;
 	}
	vector<int> ans;
	sort(vl.begin(),vl.end());
	for(int i = 0;i < vl.size();++i) {
		
		if(vl[i] != 1 ){
			if(!ans.size() || vl[i] != ans.back()) ans.push_back(vl[i]);
	}
}
	//cout << ans.size() << endl;
	if(ans.size() > 1) return cout << "NO\n" ,0;
	if(ans.size() == 0) return !printf("YES\n%lld %lld",INF,INF);
	//if(ans.size() == 1) ans.push_back(ans[0]);
	for(int i = 2;i <= n;++i) {
		if(abs(a[i] - a[i - 1]) == 1 && min(a[i],a[i - 1]) % ans[0] == 0) return cout<<"NO",0;;
	}
	cout << "YES\n" << INF <<' '<<ans[0]; 
	//cout << ans[0] << endl;
}