#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){

	int n,q;
	cin>>n>>q;
	
	vector<bool> F(2*n,false);
	
	set<pair<int,int>> S;
	
	for(int i=0;i<q;i++){
		int r,c;
		scanf("%d %d",&r,&c);
		r--;c--;
		
		int k = r*n+c;
		
		if(F[k]){
			F [k] = false;
			if(k<n){
				if(F[k+n]){
					S.erase({k,k+n});
				}
				if(k!=0&&F[k+n-1]){
					S.erase({k,k+n-1});
				}
				if(k!=n-1&&F[k+n+1]){
					S.erase({k,k+n+1});
				}
			}
			else{
				if(F[k-n]){
					S.erase({k-n,k});
				}
				if(k!=n&&F[k-n-1]){
					S.erase({k-n-1,k});
				}
				if(k!=2*n-1&&F[k-n+1]){
					S.erase({k-n+1,k});
				}
			}
		}
		else{
			F[k] = true;
			if(k<n){
				if(F[k+n]){
					S.insert({k,k+n});
				}
				if(k!=0&&F[k+n-1]){
					S.insert({k,k+n-1});
				}
				if(k!=n-1&&F[k+n+1]){
					S.insert({k,k+n+1});
				}
			}
			else{
				if(F[k-n]){
					S.insert({k-n,k});
				}
				if(k!=n&&F[k-n-1]){
					S.insert({k-n-1,k});
				}
				if(k!=2*n-1&&F[k-n+1]){
					S.insert({k-n+1,k});
				}
			}
		}
		
		if(S.size()==0)printf("Yes\n");
		else printf("No\n");
		
	}
	
	
	return 0;
}