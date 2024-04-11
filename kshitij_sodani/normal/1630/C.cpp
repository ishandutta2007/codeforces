//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int n;
int it[200001];
vector<int> ss[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
		ss[it[i]].pb(i);
	}
	vector<pair<int,int>> tt;
	for(int i=1;i<=n;i++){
		if(ss[i].size()>=2){
			tt.pb({ss[i][0],ss[i].back()});
		}
	}
	sort(tt.begin(),tt.end());
	
	vector<pair<int,int>> ee;
	vector<pair<int,int>> ff;
	for(auto j:tt){
		if(ee.size()==0){
			ee.pb(j);
			ff.pb(j);
			continue;
		}

		if(j.b<ee.back().b){
			continue;
		}

		if(j.a>ee.back().b){
			ff.pb(j);
		}
		else{
			ff[ff.size()-1].b=max(ff[ff.size()-1].b,j.b);
		}

		ee.pb(j);

	}
	vector<pair<int,int>> cot;
	int ind=0;
	while(ind<ee.size()){
		if(cot.size()==0){
			cot.pb(ee[ind]);
			ind++;
			continue;
		}
		if(ee[ind].a>cot.back().b){
			cot.pb(ee[ind]);
			ind++;
			continue;
		}
		int ma=-1;
		for(int j=ind;j<ee.size();j++){
			if(ee[j].a>cot.back().b){
				break;
			}
			ma=j;
		}
		cot.pb(ee[ma]);
		ind=ma+1;

	}
	int ans=0;
	for(auto j:ff){
		ans+=j.b-j.a-1;
	}
	ans-=(cot.size()-ff.size());
	cout<<ans<<endl;






 
	return 0;
}