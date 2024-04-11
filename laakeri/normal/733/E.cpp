#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> dpos;
vector<int> upos;

ll ust[1010101];
ll dst[1010101];
ll usu(int a, int b){
	if (a>b) return 0;
	if (a==0) return ust[b];
	return ust[b]-ust[a-1];
}
ll dsu(int a, int b){
	if (a>b) return 0;
	if (a==0) return dst[b];
	return dst[b]-dst[a-1];
}
int n;

ll solve(int i){
	int gtd=dpos.end()-lower_bound(dpos.begin(), dpos.end(), i);
	int lwu=lower_bound(upos.begin(), upos.end(), i)-upos.begin();
	if (gtd<=lwu){
		ll ans=-i+n;
		ans+=dsu(i, n-1)*2;
		ans-=usu(upos[lwu-gtd], i-1)*2;
		return ans;
	}
	else{
		ll ans=-i+1;
		ans+=dsu(i, dpos[dpos.size()-gtd+lwu])*2;
		ans-=usu(0, i-1)*2;
		return ans;
	}
}

void pp(string s){
	upos.clear();
	dpos.clear();
	for (int i=0;i<=n;i++){
		ust[i]=0;
		dst[i]=0;
	}
	for (int i=0;i<(int)s.size();i++){
		if (i>0){
			ust[i]+=ust[i-1];
			dst[i]+=dst[i-1];
		}
		if (s[i]=='U'){
			upos.push_back(i);
			ust[i]+=(ll)i;
		}
		if (s[i]=='D'){
			dpos.push_back(i);
			dst[i]+=(ll)i;
		}
	}
}

ll v[1010101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>n>>s;
	pp(s);
	for (int i=0;i<n;i++){
		if (s[i]=='U') v[i]=solve(i);
	}
	reverse(s.begin(), s.end());
	for (int i=0;i<n;i++) {
		if (s[i]=='D') s[i]='U';
		else s[i]='D';
	}
	pp(s);
	for (int i=0;i<n;i++){
		if (s[i]=='U') v[n-i-1]=solve(i);
	}
	for (int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
}