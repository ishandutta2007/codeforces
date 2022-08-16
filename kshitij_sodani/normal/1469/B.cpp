//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ma=0;
		int su=0;
		for(int i=0;i<n;i++){
			int aa;
			cin>>aa;
			su+=aa;
			ma=max(ma,su);
		}
		int m;
		cin>>m;
		int ma2=0;
		int su2=0;
		for(int i=0;i<m;i++){
			int aa;
			cin>>aa;
			su2+=aa;
			ma2=max(ma2,su2);
		}
		cout<<ma+ma2<<endl;

	}





	return 0;
}