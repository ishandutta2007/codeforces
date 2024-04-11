#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

const int c=300;

int cp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	if (a.F.F/c==b.F.F/c){
		return a.F.S<b.F.S;
	}
	else{
		return a.F.F<b.F.F;
	}
}

int a[101010];
int h[3010101];
ll vv[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	vector<pair<pair<int, int>, int> > qq(m);
	for (int i=0;i<m;i++){
		cin>>qq[i].F.F>>qq[i].F.S;
		qq[i].F.F--;
		qq[i].F.S;
		qq[i].S=i;
	}
	sort(qq.begin(), qq.end(), cp);
	int l=0;
	int r=-1;
	ll v=0;
	for (auto q:qq){
		while (r<q.F.S){
			r++;
			h[a[r]]++;
			v+=(ll)h[a[r]^k];
		}
		while (l>q.F.F){
			l--;
			h[a[l]]++;
			v+=(ll)h[a[l]^k];
		}
		while (r>q.F.S){
			v-=(ll)h[a[r]^k];
			h[a[r]]--;
			r--;
		}
		while (l<q.F.F){
			v-=(ll)h[a[l]^k];
			h[a[l]]--;
			l++;
		}
		vv[q.S]=v;
		if (k==0){
			vv[q.S]-=(ll)(q.F.S-q.F.F+1ll);
		}
	}
	for (int i=0;i<m;i++){
		cout<<vv[i]<<'\n';
	}
}