#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int n;
long long s;


pair<bool,int> solve(vector<long long> a,int k){
	pair<bool,int> ans;
	vector<long long> x;
	for(int i=0;i<a.size();i++){
		x.push_back(a[i]+(long long)k*(i+1));
	}
	sort(x.begin(),x.end());
	long long su = 0;
	for(int i=0;i<k;i++){
		su += x[i];
	}
	if(su <= s){
		ans = make_pair(1,(int)su);
	}else{
		ans = make_pair(0,0);
	}
	return ans;
}


pair<int,int> binary_search(vector<long long> a){
	int  ok = 0;
	int ng = n+1;
	pair<bool,int> x;
	while(abs(ok-ng)>1){
		int mid = (ok+ng)/2;
		x = solve(a,mid);
		if(x.first){
			ok = mid;
		}else{
			ng = mid;
		}
	}
	x = solve(a,ok);
	return make_pair(ok,x.second);
}
int main(){
	cin >> n >> s;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	pair<int,long long> ans;
	ans = binary_search(a);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}