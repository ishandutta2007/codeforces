//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

int t;
int it[100001];
int ask(int i,int j,int k){
	cout<<"? "<<i+1<<" "<<j+1<<" "<<k+1<<endl;
	int x;
	cin>>x;
	return 1-x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ind=-1;
		int ind2=-1;
		for(int i=0;i<n;i+=3){
			it[i]=ask(i,i+1,i+2);
			if(it[i]==0){
				ind=i;
			}
			if(it[i]==1){
				ind2=i;
			}
		}
		int ind3=ind;
		int ind4=ind2;
		if(ask(ind,ind+1,ind2)==1 or ask(ind,ind+1,ind2+1)==1){
			if(ask(ind,ind+2,ind2)==1 or ask(ind,ind+2,ind2+1)==1){
				ind3++;
			}
			else{

			}
		}
		else{

		}
		if(ask(ind2,ind2+1,ind3)==0 ){
			if(ask(ind2,ind2+2,ind3)==0){
				ind4++;
			}
		}
	

		ind=ind3;
		ind2=ind4;
		set<int> ans;
		for(int i=0;i<n;i+=3){
			if(it[i]==0){
				if(ask(ind2,i,i+1)==0){
					if(ask(ind2,i,i+2)==1){
						ans.insert(i+2);
					}
				}
				else{
					if(ask(ind2,i,i+2)==1){
						ans.insert(i);
					}
					else{
						ans.insert(i+1);
					}
				}
			}
			else{
				ans.insert(i);
				ans.insert(i+1);
				ans.insert(i+2);
				if(ask(ind,i,i+1)==1){
					if(ask(ind,i,i+2)==0){
						ans.erase(i+2);
					}
				}
				else{
					if(ask(ind,i,i+2)==0){
						ans.erase(i);
					}
					else{
						ans.erase(i+1);
					}
				}
			}
		}
		cout<<"! "<<ans.size()<<" ";
		for(auto j:ans){
			cout<<j+1<<" ";
		}
		cout<<endl;
		

	}





 
	return 0;
}