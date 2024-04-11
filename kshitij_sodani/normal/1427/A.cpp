
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int it[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int su=0;
		for(int i=0;i<n;i++){
			cin>>it[i];
			su+=it[i];
		}
		if(su==0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			sort(it,it+n);
			int aa=0;
			int	bb=0;
			for(int i=0;i<n;i++){
				if(it[i]<=0){
					aa+=it[i];
				}
				else{
					bb+=it[i];
				}
			}
			aa=-aa;
			if(aa>bb){
				for(int i=0;i<n;i++){
					cout<<it[i]<<" ";
				}
				cout<<endl;
			}
			else{
				for(int i=0;i<n;i++){
					cout<<it[n-i-1]<<" ";
				}
				cout<<endl;
			}
		}
	}


	return 0;
}