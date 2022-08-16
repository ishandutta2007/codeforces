//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int aa[200001];
int bb[200001];
int n;
bool check(int mid){
	int ind=0;
	for(int i=0;i<n;i++){

		if(ind<=aa[i] and mid-ind-1<=bb[i]){
			ind++;

		}
		if(ind==mid){
			return true;
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>aa[i]>>bb[i];
			swap(aa[i],bb[i]);
		}
		int low=1;
		int high=n;
		while(low<high-1){
			int mid=(low+high)/2;
			if(check(mid)){
				low=mid;
			}
			else{
				high=mid;
			}
		}
		int ans=low;
		if(check(high)){
			ans=high;
		}
		cout<<ans<<endl;






	}



 
	return 0;
}