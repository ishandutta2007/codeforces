#include <bits/stdc++.h>
using namespace std;



int main(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> V(n,vector<int>(m));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>V[i][j];
		}
	}
	int a = 0;
	for(int i=0;i<n;i++){
		a^=V[i][0];
	}
	if(a!=0){
		cout<<"TAK"<<endl;
		for(int i=0;i<n;i++){
			if(i!=0)cout<<' ';
			cout<<1;
		}
		cout<<endl;
		return 0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			if(V[i][0]!=V[i][j]){
				cout<<"TAK"<<endl;
				for(int k=0;k<n;k++){
					if(k!=0)cout<<' ';
					if(k!=i)cout<<1;
					else cout<<j+1;
				}
				cout<<endl;
				return 0;
			}
		}
	}
	
	cout<<"NIE"<<endl;
	
	
	return 0;
}