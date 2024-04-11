#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(m<n){
			cout<<"No"<<endl;
			continue;
		}
		if(n==1){
			cout<<"Yes"<<endl;
			cout<<m<<endl;
			continue;
		}
		if(n%2==0){
			if(m%2==0){
				cout<<"Yes"<<endl;
				for(int i=0;i<n;i++){
					if(i>=2){
						cout<<1<<" ";
					}
					else{
						cout<<(1+((m-n)/2))<<" ";
					}
				}
				cout<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
		else{
		/*	if(m==n){
				cout<<"No"<<endl;
			}
			else{*/
				cout<<"Yes"<<endl;
				for(int i=0;i<n;i++){
					if(i>=1){
						cout<<1<<" ";
					}
					else{
						cout<<1+(m-n)<<" ";
					}
				}
				cout<<endl;
		//	}
		}
	}






	return 0;
}