#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n,q,m,x;
	int ans[100001]={};
	vector<int> v;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++){
		for(int j=v[i];j<=v[i+1];j++){
			ans[j]=i+1;
		}
	}
	cin >> q;
	for(int k=0;k<q;k++){
		cin >> m;
		if(m>=v[v.size()-1]){
			cout << v.size() <<endl;
		}else cout << ans[m] << endl;
	}
	return 0;
}