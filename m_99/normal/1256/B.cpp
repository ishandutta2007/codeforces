#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> p(n);
		rep(i,n){
			cin>>p[i];
		}
		
		vector<bool> used(n-1,false);
		
		rep(__,n-1){
			int ind = -1;
			rep(i,n-1){
				if(used[i])continue;
				if(p[i]>p[i+1]){
					if(ind==-1 || (p[i+1]<p[i]&&p[i+1]<p[ind+1]))ind = i;
				}
			}
		//	cout<<ind<<endl;
			if(ind==-1)break;
			if(p[ind+1]<p[ind]){
				used[ind] = true;
				swap(p[ind],p[ind+1]);
			}
		}
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<p[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}