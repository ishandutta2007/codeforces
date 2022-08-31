#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[100001];
vector<int> pre[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			pre[i].clear();
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
			it[i]--;
			pre[it[i]].pb(i);
		}
		for(int i=0;i<n;i++){
			int ma=0;
			int ma2=0;
			for(auto j:pre[i]){
				if(j%2==1){
					ma2=max(ma2,ma+1);
				}
				else{
					ma=max(ma,ma2+1);
				}
			}
			cout<<max(ma,ma2)<<" ";
		}
		cout<<endl;

	}





	return 0;
}