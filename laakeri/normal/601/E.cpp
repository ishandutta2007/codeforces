#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll cp=1e7+19;
const ll mod=1e9+7;

int add[20202];
int rm[20202];
ll v[20202];
int w[20202];
ll vv[30303];
int qq[30303];

int n,k;

ll dp[1010];

void addn(int e, vector<pair<int, ll> >&st){
	for (int i=k;i>=w[e];i--){
		if (dp[i-w[e]]!=-1){
			if (dp[i]<dp[i-w[e]]+v[e]){
				st.push_back({i, dp[i]});
				dp[i]=dp[i-w[e]]+v[e];
			}
		}
	}
}

void go(int l, int r, vector<int> es){
	if (l>r) return;
	vector<pair<int, ll> > st;
	vector<int> ces;
	for (int e:es){
		if (rm[e]<l||add[e]>r) continue;
		if (add[e]<=l&&r<=rm[e]){
			addn(e, st);
		}
		else{
			ces.push_back(e);
		}
	}
	if (l==r&&qq[l]==1){
		ll ma=0;
		ll pp=1;
		for (int i=1;i<=k;i++){
			ma=max(ma, dp[i]);
			vv[l]+=(ma%mod)*(pp%mod);
			vv[l]%=mod;
			pp*=cp;
			pp%=mod;
		}
	}
	if (l<r){
		int mid=(l+r)/2;
		go(l, mid, ces);
		go(mid+1, r, ces);
	}
	while ((int)st.size()>0){
		dp[st.back().F]=st.back().S;
		st.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for (int i=1;i<=k;i++){
		dp[i]=-1;
	}
	vector<int> es;
	for (int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
		add[i]=0;
		es.push_back(i);
	}
	int i2=n+1;
	int q;
	cin>>q;
	vector<int> q3s;
	for (int i=1;i<=q;i++){
		int t;
		cin>>t;
		if (t==1){
			es.push_back(i2);
			cin>>v[i2]>>w[i2];
			add[i2]=i;
			i2++;
		}
		if (t==2){
			int x;
			cin>>x;
			rm[x]=i;
		}
		if (t==3){
			q3s.push_back(i);
			qq[i]=1;
		}
	}
	for (int i=1;i<i2;i++){
		if (rm[i]==0){
			rm[i]=q+1;
		}
	}
	go(0, q+1, es);
	for (int q3:q3s){
		cout<<vv[q3]<<'\n';
	}
}