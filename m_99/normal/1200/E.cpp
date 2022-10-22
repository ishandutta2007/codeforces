#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 10000000000000000



int main(){
	int n;
	cin>>n;
	vector<string> V(n);
	for(int i=0;i<n;i++){
		cin>>V[i];
	}
	
	string ans;
	
	for(int i=0;i<n;i++){
		if(i==0){
			ans = V[i];
			continue;
		}
		
		int a = min(ans.size(),V[i].size());
		int rev = ans.size()-a;
		string s = ans.substr(ans.size()-a);
		string t = V[i].substr(0,a);
		string S = t + ' ' + s;
		vector<int> A(S.size()+1,-1);
		int x = -1;
		for(int j=0;j<S.size();j++){
			while(x>=0){
				if(S[j]==S[x])break;
				x=A[x];
			}
			x++;
			if(j!=S.size()-1){
				if(S[j+1] == S[x]) {
					A[j+1] = A[x];
					continue;
				}
			}
			A[j+1] = x;
		}
			
		ans += V[i].substr(A[S.size()]);
				
		
		/*
		vector<int> A(a+1,-1);
		int x = 0;
		
				
		for (int j = 0; j < a; j++) {
			while (x >= 0){
			  if(ans[rev+j]==V[i][x])break;
			  x = A[x];
			}

			x++;
			//  A[i+1] = j;
			//A[j+1] = x;
			if (j!=a-1){
				if(ans[rev+j] == V[i][x+1]){
					A[j+1] = A[x];
					continue;
				}
			}
			A[j+1] = x;
		  
		}
		
		
		ans += V[i].substr(A[a]);
		
		*/
	}
	
	cout<<ans<<endl;
			
			
	
	
	return 0;
}