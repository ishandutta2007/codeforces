#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<multiset<int>> VA(n+m),VB(n+m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int A;
			scanf("%d",&A);
			VA[i+j].insert(A);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int A;
			scanf("%d",&A);
			VB[i+j].insert(A);
		}
	}
	
	if(VA==VB)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
    return 0;
}