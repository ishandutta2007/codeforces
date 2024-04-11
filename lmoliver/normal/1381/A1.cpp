#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=100100;
char a[N],b[N];
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cin>>a;
		cin>>b;
		ans.clear();
		bool rev=false;
		bool fli=false;
		int l=0;
		for(int i=n-1;i>=0;i--){
			bool cur=(a[l+(rev?i:0)]=='1')^fli;
			if(cur==(b[i]=='1')){
				ans.push_back(1);
			}
			ans.push_back(i+1);
			if(!rev)l++;
			rev^=1;
			fli^=1;
		}
		cout<<ans.size();
		for(size_t i=0;i<ans.size();i++){
			cout<<" "<<ans[i];
		}
		cout<<endl;
		// for(size_t i=0;i<ans.size();i++){
		// 	int x=ans[i];
		// 	for(int i=0;i<x;i++)a[i]^=1;
		// 	reverse(a,a+x);
		// }
		// for(int i=0;i<n;i++){
		// 	assert(a[i]==b[i]);
		// }
	}
	return 0;
}