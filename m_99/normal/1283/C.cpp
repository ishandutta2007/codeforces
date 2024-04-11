#include <bits/stdc++.h>
using namespace std;
#define modulo 100000
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	
	set<int> S;
	
	for(int i=0;i<n;i++)S.insert(i+1);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		S.erase(a[i]);
	}
	
	vector<int> ans = a;
	
	vector<int> L;
	vector<int> ind;
	
	for(int i=0;i<n;i++){
		if(a[i]==0){
			ind.push_back(i);
			if(S.count(i+1)){
				S.erase(i+1);
				L.push_back(i+1);
			}
			else{
				L.push_back(0);
			}
		}
	}
	
	for(int i=0;i<L.size();i++){
		if(L[i]==0){
			L[i] = (*S.begin());
			S.erase(S.begin());
		}
	}
	
	int l = L.back();
	L.pop_back();
	L.insert(L.begin(),l);
	
	for(int i=0;i<L.size();i++){
		ans[ind[i]] = L[i];
	}
	
	for(int i=0;i<n;i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	
	cout<<endl;
	
    return 0;
}