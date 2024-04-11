#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int a[100001]={};
	int n,m,k,u,v,l,x,ans;
	ans =-1;
	cin >>n>>m>>k;
	vector<pair<int,pair<int,int> > > vec(m);
	for(int i=0;i<m;i++){
		cin >> u >> v >> l;
		vec[i] = make_pair(l,make_pair(u,v));
	}
	sort(vec.begin(),vec.end());
	for(int j=0;j<k;j++){
		cin >> x;
		a[x]=1;
	}
	for(int y=0;y<m;y++){
		if(a[vec[y].second.first]==0&&a[vec[y].second.second]==1){
			ans = vec[y].first;
			break;
		}
		if(a[vec[y].second.first]==1&&a[vec[y].second.second]==0){
			ans = vec[y].first;
			break;
		}
	}
	cout << ans <<endl;
	return 0;
}