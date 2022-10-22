#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n;
	cin>>n;
	
	string s;
	cin>>s;

	vector<int> ind(n);
	for(int i=0;i<n;i++){
		ind[i] = i;
	}

	string ans(n,'2');

	
	
	for(int i=0;i<n;i++){

		char mini = '{';
		int ii = -1;
		
		for(int j=0;j<ind.size();j++){
			if(s[ind[j]] < mini){
				mini = s[ind[j]];
				ii = j;
			}
		}
		
		set<int> S;
		for(int j=0;j<ii;j++){
			S.insert(ans[ind[j]]);
		}
		
		S.erase('2');
		
		if(S.size()>=2){
			cout<<"NO"<<endl;
			return 0;
		}
		
		if(S.count(ans[ind[ii]])){
			cout<<"NO"<<endl;
			return 0;
		}
		
		char a = '0';
		char b = '1';
		if(S.count('1'))swap(a,b);
		if(ans[ind[ii]]==a)swap(a,b);
		
		for(int j=0;j<ii;j++){
			ans[ind[j]] = a;
		}
		ans[ind[ii]] = b;
		ind.erase(ind.begin() + ii);
	}
	
	cout<<"YES"<<endl;
	cout<<ans<<endl;
	
    return 0;
}