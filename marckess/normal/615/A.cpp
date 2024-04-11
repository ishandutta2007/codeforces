#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	int m;
	int n;
	cin>>n>>m;
	vector<int> v(m+1,0);
	while(n-->0){
		int x,aux;
		cin>>x;
		while(x-->0){
			cin>>aux;
			v[aux]++;
		}
	}
	bool f = true;
	for(int i=1;i<=m;i++){
		if(v[i]==0)
			f= false;
	}	
	if(f)
		cout<<"YES";
	else
		cout<<"NO";
}