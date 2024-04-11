#include <bits/stdc++.h>
using namespace std;
#define modulo m
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>> E(n,vector<int>());
	
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	vector<bool> used(n,false);
	
	while(true){
		vector<int> S;
		for(int i=0;i<n;i++){
			if(E[i].size()==1){
				S.push_back(i);
			}
		}
		
		if(S.size()==0){
			for(int i=0;i<n;i++){
				if(used[i]==false){
					printf("! %d",i+1);
					cout<<endl;
					return 0;
				}
			}
		}
		
		printf("? %d %d",S[0]+1,S[1]+1);
		cout<<endl;
		int ret;
		scanf("%d",&ret);
		ret--;
		
		if(ret==S[0]){
			printf("! %d",S[0]+1);
			cout<<endl;
			return 0;
		}
		
		if(ret==S[1]){
			printf("! %d",S[1]+1);
			cout<<endl;
			return 0;
		}
		
		used[S[0]]=true;
		used[S[1]]=true;
		
		vector<vector<int>> copy(n,vector<int>());
				
		for(int i=0;i<E.size();i++){
			if(used[i])continue;
			for(int j=0;j<E[i].size();j++){
				if(used[E[i][j]])continue;
				copy[i].push_back(E[i][j]);
			}
		}
		E = copy;
	}
			
	
	return 0;
}