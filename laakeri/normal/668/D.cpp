// TCR
// Sample code on how to use g++ ordered set
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
//using namespace pb_ds;

typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> oset;

int rcc1[1010101];
int rcc2[1010101];

oset h[1010101][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> cc1;
	vector<int> cc2;
	vector<pair<int, pair<int, int> > > qs(n);
	for (int i=0;i<n;i++){
		cin>>qs[i].F>>qs[i].S.F>>qs[i].S.S;
		cc1.push_back(qs[i].S.F);
		cc2.push_back(qs[i].S.S);
	}
	sort(cc1.begin(), cc1.end());
	cc1.erase(unique(cc1.begin(), cc1.end()), cc1.end());
	sort(cc2.begin(), cc2.end());
	cc2.erase(unique(cc2.begin(), cc2.end()), cc2.end());
	for (int i=0;i<(int)cc1.size();i++){
		rcc1[i]=cc1[i];
	}
	for (int i=0;i<(int)cc2.size();i++){
		rcc2[i]=cc2[i];
	}
	for (int i=0;i<n;i++){
		qs[i].S.F=lower_bound(cc1.begin(), cc1.end(), qs[i].S.F)-cc1.begin();
		qs[i].S.S=lower_bound(cc2.begin(), cc2.end(), qs[i].S.S)-cc2.begin();
		if (qs[i].F==1){
			h[qs[i].S.S][0].insert({qs[i].S.F, i});
		}
		else if(qs[i].F==2){
			h[qs[i].S.S][1].insert({qs[i].S.F, i});
		}
		else{
			int v=h[qs[i].S.S][0].order_of_key({qs[i].S.F, n+1});
			v-=h[qs[i].S.S][1].order_of_key({qs[i].S.F, n+1});
			cout<<v<<'\n';
		}
	}
}