#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back

const int MAXN=110;
vector<ii> wh[MAXN];

vector<int> get(int i){
	sort(ALL(wh[i])); reverse(ALL(wh[i]));
	ll sum=0;
	vector<int> ans;
	for(auto x:wh[i]){
		if(sum+x.fst>=0) sum+=x.fst;
		else ans.pb(x.snd);
	}
	return ans;
}

int main() {FIN;
	int n,k; cin>>n>>k;
	fore(i,0,k){
		vector<int> a(n);
		fore(j,0,n) cin>>a[j];
		fore(j,0,n-1) wh[j].pb({a[j]-a[n-1],i});
	}
	vector<int> ans(k); fore(i,0,k) ans[i]=i;
	fore(i,0,n-1){
		auto now=get(i);
		if(SZ(now)<SZ(ans)) ans=now;
	}
	cout<<SZ(ans)<<"\n";
	for(auto x:ans)cout<<x+1<<" ";cout<<"\n";
	
}