#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int it[100001];
int ans[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cur=-1;
		int su=0;
		int st=1;
		int ind=-1;
		for(int i=0;i<n;i++){
			cin>>it[i];
			ans[i]=i+1;
			if(it[i]!=cur){
				if(su==1){
					st=0;
				}

				su=1;	
				cur=it[i];
				if(ind>=0){
					ans[i-1]=ind;
				}
				ind=i;				
			}	
			else{
				su++;
			}	
		}
		if(su==1){
			st=0;
		}
		ans[n-1]=ind;
		if(st==0){
			cout<<-1<<endl;
		}
		else{
			for(int i=0;i<n;i++){
				cout<<ans[i]+1<<" ";
			}
			cout<<endl;
		}
	}







	return 0;
}