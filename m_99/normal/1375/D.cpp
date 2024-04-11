#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		
		vector<int> ans;
		while(true){
			int mex = -1;
			vector<bool> exists(n+1,false);
			for(int i=0;i<n;i++)exists[a[i]]=true;
			for(int i=0;i<=n;i++){
				if(!exists[i]){
					mex=i;
					break;
				}
			}
			if(mex!=n){
				ans.push_back(mex+1);
				a[mex] = mex;
			}
			else{
				int ind = -1;
				for(int i=0;i<n;i++){
					if(a[i]!=i){
						ind = i;
						break;
					}
				}
				if(ind==-1)break;
				for(int i=ind+1;i<n;i++){
					if(a[i]==ind){
						ans.push_back(i+1);
						a[i] = mex;
						break;
					}
				}
			}
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		
	}
		
	return 0;
}