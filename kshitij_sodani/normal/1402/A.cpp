#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 
llo n;
llo it[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	if(n==1){
		cout<<"1 1"<<endl;
		cout<<-it[0]<<endl;
		cout<<"1 1"<<endl;
		cout<<0<<endl;
		cout<<"1 1"<<endl;
		cout<<0<<endl;
		return 0;

	}
	cout<<1<<" "<<n<<endl;
	for(llo i=0;i<n;i++){
		llo co=0;
		if(it[i]<0){
			co+=(-it[i])/n;
			co+=1;
			co*=n;
		}
		co+=n*((n-1)-(it[i]+co)%(n-1));
		cout<<co<<" ";
		it[i]+=co;
	}
	cout<<endl;
	cout<<1<<" "<<n-1<<endl; 
	for(llo i=0;i<n-1;i++){
		cout<<-it[i]<<" ";
		it[i]=0;
	}
	cout<<endl;
	cout<<2<<" "<<n<<endl;
	for(llo i=1;i<n;i++){
		cout<<-it[i]<<" ";
		it[i]=0;
	}	
	cout<<endl;





	return 0;
}