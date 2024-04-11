#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int it[100001];
int n;
bool check(int mid){
	vector<int> kk;
	int su=mid;
	int xx=0;
	int zz=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if(it[i]==1){
			if(su>0){
				su--;
				xx++;
				continue;
			}
			kk.pb(i);
			zz=1;
		}
		else{
			ans+=zz;
			kk.pb(i);
		}
	}
	if(ans>xx){
		return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		
		cin>>n;
		set<int> ss;
		set<int> tt;
		for(int i=0;i<n;i++){
			cin>>it[i];
			if(it[i]==0){
				ss.insert(i);
			}
			else{
				tt.insert(i);
			}
		}
		int low=-1;
		for(int j=19;j>=0;j--){
			if(low+(1<<j)>tt.size()){
				continue;
			}
			if(check(low+(1<<j))==false){
				low+=(1<<j);
			}
		}
		cout<<low+1<<endl;
	}






	return 0;
}