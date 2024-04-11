#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

void answer(vector<int> ans){
	cout<<"!";
	rep(i,ans.size()){
		cout<<" "<<ans[i];
	}
	cout<<endl;
}

int question(int a,int b){
	cout<<"? "<<a<<' '<<b<<endl;
	int ret;
	cin>>ret;
	return ret;
}

int main(){
	
	int n;
	cin>>n;
	
	int last = 0;
	vector<int> ans(n,-1);
	for(int i=1;i<n;i++){
		int x = question(last+1,i+1);
		int y = question(i+1,last+1);
		if(x>y){
			ans[last] = x;
			last = i;
		}
		else{
			ans[i] = y;
		}
		//answer(ans);
	}
	
	set<int> S;
	rep(i,n)S.insert(i+1);
	rep(i,n){
		S.erase(ans[i]);
	}
	ans[last] = *(S.begin());
	
	answer(ans);
	
    return 0;
}