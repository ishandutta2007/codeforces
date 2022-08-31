#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
//#define endl '\n'
int aa[501];
int bb[501];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>aa[i];
		}
		for(int i=0;i<n;i++){
			cin>>bb[i];
		}
		if(n%2==1){
			if(aa[n/2]!=bb[n/2]){
				cout<<"No";
				cout<<endl;
				continue;
			}
		}
		vector<pair<int,int>> cc;
		vector<pair<int,int>> dd;
		for(int i=0;i<n/2;i++){
			cc.pb({min(aa[i],aa[n-i-1]),max(aa[i],aa[n-i-1])});
			dd.pb({min(bb[i],bb[n-i-1]),max(bb[i],bb[n-i-1])});
		}
		sort(cc.begin(),cc.end());
		sort(dd.begin(),dd.end());
		cout<<((cc==dd)?"Yes":"No");
						cout<<endl;



		

		



		




	}
	

	return 0;
}