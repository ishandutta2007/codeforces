#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n),b(n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)scanf("%d",&b[i]);
		map<int,int> mp;
		int last = -1;
		bool f = true;
		while(a.size()>0){
			if(b.size()!=0){
				if(a.back()==b.back()){
					last = b.back();
					a.pop_back();
					b.pop_back();
				}
				else if(b.back()==last){
					mp[b.back()]++;
					b.pop_back();
				}
				else{
					if(mp[a.back()]==0){
						f = false;
						break;
					}
					mp[a.back()]--;
					a.pop_back();
				}
			}
			else{
				if(mp[a.back()]==0){
					f = false;
					break;
				}
				mp[a.back()]--;
				a.pop_back();
			}
		}
		//auto x = get(a),y = get(b);
		if(f)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}