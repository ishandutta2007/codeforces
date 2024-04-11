#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){

	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n)scanf("%d",&a[i]);
	
	sort(a.begin(),a.end());
	
	int ok = 0,ng = (n-1)/2 + 1;
	
	while(ng-ok>1){
		int mid = (ok+ng)/2;
		vector<int> t;
		rep(i,mid+1){
			t.push_back(a[a.size()-1-i]);
			if(i==mid)break;
			t.push_back(a[mid-1-i]);
		}
		bool f = true;
		rep(i,t.size()-1){
			if(t[i]==t[i+1]){
				f=false;
				break;
			}
		}
		if(f)ok = mid;
		else ng = mid;
	}
	vector<int> ans;
	rep(i,ok+1){
		ans.push_back(a.back());
		a.pop_back();
		if(i==ok)break;
		ans.push_back(a[ok-1-i]);
	}

	while(ans.size()!=n){
		ans.push_back(a.back());
		a.pop_back();
	}
	
	cout<<ok<<endl;
	rep(i,n){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	cout<<endl;

	return 0;
}