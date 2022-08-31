//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int aa,bb;
		cin>>aa>>bb;
		set<int> ans;
		int co=0;
		int co2=0;
		int x=(aa+bb)/2;
		int y=aa+bb-x;

		for(int i=0;i<=aa;i++){
			//i in x
			//aa-i in y
			if(i<=x and aa-i<=y){
				ans.insert(aa-i+(x-i));
			}
		}
		swap(aa,bb);
		for(int i=0;i<=aa;i++){
			//i in x
			//aa-i in y
			if(i<=x and aa-i<=y){
				ans.insert(aa-i+(x-i));
			}
		}
		cout<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j<<" ";
		}
		cout<<endl;

	}





 
 
 
	return 0;
}