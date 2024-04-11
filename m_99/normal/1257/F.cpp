#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001



int main(){
	
	int n;
	cin>>n;
	
	vector<int> a1(n),a2(n);
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a1[i] = x>>15;
		a2[i] = x%(1<<15);
	}
	
	map<vector<int>,int> mp;
	
	for(int i=0;i<(1<<15);i++){
		vector<int> X(n);
		for(int j=0;j<n;j++){
			int x = i^a1[j];
			int C = 0;
			for(int k=0;k<15;k++){
				if((x>>k)&1)C++;
			}
			X[j] = C;
		}
		mp[X] = i;
	}
	
	for(int i=0;i<(1<<15);i++){
		vector<int> X(n);
		for(int j=0;j<n;j++){
			int x = i^a2[j];
			int C = 0;
			for(int k=0;k<15;k++){
				if((x>>k)&1)C++;
			}
			X[j] = C;
		}
		for(int j=0;j<=30;j++){
			vector<int> Y = X;
			for(int k=0;k<n;k++){
				Y[k] = j-X[k];
			}
			if(mp.count(Y)){
				int A = mp[Y];
				int B = i;
				cout<<((A<<15)|B)<<endl;
				return 0;
			}
		}
	}
	
	cout<<-1<<endl;
	
	
    return 0;
}