#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((mod_x)%modulo)
#define Inf 1000000001

vector<int> func(auto x,auto y){
	vector<int> ret = x;
	
	if(ret[0]>=y[0]&&ret[2]<=y[2]){
		if(ret[1]>=y[1]&&ret[3]<=y[3]){
			ret[2]=ret[0];
			ret[3]=ret[1];
			return ret;
		}
		if(ret[1]>=y[1]){
			ret[1] = max(y[3],ret[1]);
		}
		
		if(ret[3]<=y[3]){
			ret[3] = min(y[1],ret[3]);
		}
		
	}
	
	if(ret[1]>=y[1]&&ret[3]<=y[3]){
		if(ret[0]>=y[0]){
			ret[0] = max(y[2],ret[0]);
		}
		if(ret[2]<=y[2]){
			ret[2] = min(y[0],ret[2]);
		}
	}
	return ret;
}

int main(){
	
	vector<vector<int>> P(3,vector<int>(4));
	
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cin>>P[i][j];
		}
	}
	
	P[0] = func(P[0],P[1]);
	//cout<<P[0][0]<<','<<P[0][1]<<','<<P[0][2]<<','<<P[0][3]<<endl;
	P[0] = func(P[0],P[2]);
	
	if((P[0][2]-P[0][0])==0||(P[0][3]-P[0][1])==0)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	
    return 0;
}