#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[50];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++){
			it[i]=1;
		}
		for(int i=0;i<n;i++){
			int aa;
			cin>>aa;
			aa--;
			pair<int,int> xx={aa,m-aa-1};
			if(xx.a>xx.b){
				aa=m-aa-1;
			}
			if(it[aa]==0){
				it[m-aa-1]=0;
			}
			else{
				it[aa]=0;
			}
		}
		for(int i=0;i<m;i++){
			if(it[i]==0){
				cout<<"A";
			}
			else{
				cout<<"B";
			}
		}
		cout<<endl;
	}







	return 0;
}