//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

int ask(int x,int y){
	cout<<"? "<<x+1<<" "<<y+1<<endl;
	int aa;
	cin>>aa;
	return aa;
}
int it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int ind=0;
	for(int i=1;i<n;i++){
		int x=ask(ind,i);
		int y=ask(i,ind);
		if(x>y){
			it[ind]=x;
			ind=i;
		}
		else{
			it[i]=y;
		}
		/*if(ask(i,ind)==i){
		}
		else{
			ind=i;
		}*/
	}
	it[ind]=n;
	cout<<"! ";
	for(int i=0;i<n;i++){
		cout<<it[i]<<" ";
	}
	cout<<endl;
	/*for(int i=0;i<n;i++){
		if(i!=ind){

		}
		else{

		}
	}*/



 
	return 0;
}