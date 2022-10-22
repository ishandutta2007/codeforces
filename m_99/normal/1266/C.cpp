#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int r,c;
	cin>>r>>c;
	
	if(r==1&&c==1){
		cout<<0<<endl;
		return 0;
	}
	
	vector<vector<int>> a(r,vector<int>(c));
	
	if(c!=1){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){

				a[i][j] = (r+1+j)*(i+1);
			}
		}
	}
	else{
		for(int i=0;i<r;i++){
			a[i][0] = i+2;
		}
	}
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(j!=0)cout<<' ';
			cout<<a[i][j];
		}
		cout<<endl;
	}
		
	
	return 0;
}