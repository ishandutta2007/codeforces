

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<pair<int,int>,int>> cur;
	cin>>n;
	for(int i=0;i<n;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		if(cc==1){
			cur.pb({{aa,-bb},cc});
		}
		else{
			cur.pb({{bb,-aa},cc});
		}
	}
	sort(cur.begin(),cur.end());
	multiset<int> kk;
	int ans=n;
	for(auto j:cur){
		if(j.b==2){
			if(kk.size()==0){
				continue;
			}
			auto jj=kk.upper_bound(j.a.b);
			if(jj==kk.begin()){
				continue;
			}
			jj--;
			if(*jj>j.a.b){
				continue;
			}

			kk.erase(jj);
			ans-=1;

		}
		else{
			kk.insert(j.a.b);
		}
	}
	cout<<ans<<endl;


	return 0;
}