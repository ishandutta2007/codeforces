#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	int n;
	cin>>n;
	
	vector<vector<long long>> C(n,vector<long long>(3));
	
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			cin>>C[j][i];
		}
	}
	
	vector<vector<int>> E(n,vector<int>(0));
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	int start = -1;
	for(int i=0;i<n;i++){
		if(E[i].size()==1){
			start=i;
			break;
		}
	}
	
	vector<int> L;
	L.push_back(start);
	
	for(int i=0;i<n-1;i++){
		int from = L.back();
		if(E[from].size()>=3){
			cout<<-1<<endl;
			return 0;
		}
		
		for(int j=0;j<E[from].size();j++){
			if(L.size()!=1&&E[from][j]==L[L.size()-2])continue;
			L.push_back(E[from][j]);
			break;
		}
	}
	
	long long mini = Inf;
	vector<int> P(3);
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(i==j||j==k||k==i)continue;
				long long sum = 0;
				for(int ind=0;ind<n;ind++){
					if(ind%3==0){
						sum+=C[L[ind]][i];
					}
					if(ind%3==1){
						sum+=C[L[ind]][j];
					}
					if(ind%3==2){
						sum+=C[L[ind]][k];
					}
				}
				//cout<<i<<','<<j<<','<<k<<','<<sum<<endl;
				if(sum<mini){
					mini=sum;
					P[0]=i;
					P[1]=j;
					P[2]=k;
				}
			}
		}
	}
	cout<<mini<<endl;
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		ans[L[i]] = P[i%3]+1;
	}
	
	for(int i=0;i<n;i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	
	
    return 0;
}