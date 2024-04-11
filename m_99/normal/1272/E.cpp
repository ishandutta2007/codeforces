#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	
	vector<int> disE(n,Inf),disO(n,Inf);
	queue<int> QE,QO;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2==0){
			disE[i]=0;
			QE.push(i);
		}
		else{
			disO[i]=0;
			QO.push(i);
		}
	}
	
	vector<vector<int>> E(n,vector<int>());
	
	for(int i=0;i<n;i++){
		if(i-a[i]>=0){
			E[i-a[i]].push_back(i);
		}
		if(i+a[i]<n){
			E[i+a[i]].push_back(i);
		}
	}
	
	while(QE.size()!=0){
		int from = QE.front();
		QE.pop();
		for(int i=0;i<E[from].size();i++){
			int to = E[from][i];
			if(disE[to] <= disE[from]+1)continue;
			disE[to] = disE[from]+1;
			QE.push(to);
		}
	}
	
	while(QO.size()!=0){
		int from = QO.front();
		QO.pop();
		for(int i=0;i<E[from].size();i++){
			int to = E[from][i];
			if(disO[to] <= disO[from]+1)continue;
			disO[to] = disO[from]+1;
			QO.push(to);
		}
	}
	
	for(int i=0;i<n;i++){
		if(disE[i]==Inf)disE[i]=-1;
		if(disO[i]==Inf)disO[i]=-1;
	}
	
	for(int i=0;i<n;i++){
		if(i!=0)cout<<' ';
		if(a[i]%2==0){
			cout<<disO[i];
		}
		else{
			cout<<disE[i];
		}
	}
	cout<<endl;
	
	
	
	return 0;
}