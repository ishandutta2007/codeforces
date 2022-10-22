#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<int> a(n),l(n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)scanf("%d",&l[i]);
		
		vector<int> L;
		rep(i,n){
			if(l[i]==0){
				L.push_back(a[i]);
			}
		}
		sort(L.begin(),L.end());
		
		rep(i,n){
			if(l[i]==0){
				a[i] = L.back();
				L.pop_back();
			}
		}
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
		
	}
	
    return 0;
}