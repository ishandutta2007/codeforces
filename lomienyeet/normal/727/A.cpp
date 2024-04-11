#include <bits/stdc++.h>
using namespace std;
void solve(){
	int a,b;
	cin>>a>>b;
	vector<int> vec;
	vec.push_back(b);
	while(b>0){
		if(b%2==0){
			b/=2;
			vec.push_back(b);
		}
		else if((b-1)%10==0){
			b--;
			b/=10;
			vec.push_back(b);
		}
		else break;
		if(b==a)break; 
	}
	if(vec[vec.size()-1]!=a){
		cout<<"NO\n";
		return;
	} 
	else{
		cout<<"YES\n";
		cout<<vec.size()<<"\n";
		for(int i=vec.size()-1;i>=0;i--)cout<<vec[i]<<" "; 
	}
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}