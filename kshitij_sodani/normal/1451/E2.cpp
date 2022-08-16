//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo it[1<<17];
/*void solve(llo l,llo r){
	if(r-l==1){

	}
	else{
		llo mid=(l+r)/2;
		solve(l,mid);
		for(llo i=mid+1;i<r;i++){
			cout<<<"XOR "<<
		}
	}
}*/
vector<llo> kk[1<<17];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;



	it[0]=0;
	for(llo i=1;i<n;i++){
		cout<<"XOR "<<1<<" "<<i+1<<endl;
		llo xx;
		cin>>xx;
		it[i]=xx^it[0];

	}
/*	for(llo i=0;i<n;i++){
		cout<<it[i]<<",";
	}
	cout<<endl;*/
	for(llo i=0;i<n;i++){
		kk[it[i]].pb(i);
	}
	for(llo i=0;i<n;i++){
		if(kk[i].size()>=2){
			llo ind=kk[i][0];
			llo ind2=kk[i][1];
			cout<<"AND "<<ind+1<<" "<<ind2+1<<endl;
			llo x;
			cin>>x;
			llo cur=0;
			for(llo j=0;j<30;j++){
				if((i&(1<<j))!=(x&(1<<j))){
					cur^=(1<<j);
				}
			}

			cout<<"! ";
			for(llo j=0;j<n;j++){
				it[j]^=cur;
				cout<<it[j]<<" ";
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<"AND "<<kk[0][0]+1<<" "<<kk[1][0]+1<<endl;
	llo x;
	cin>>x;
	llo cur=0;
	for(llo j=1;j<30;j++){
		if((0&(1<<j))!=(x&(1<<j))){
			cur^=(1<<j);
		}
	}

	cout<<"AND "<<kk[0][0]+1<<" "<<kk[2][0]+1<<endl;
	//llo x;
	cin>>x;
	//llo cur=0;
	for(llo j=0;j<1;j++){
		if((0&(1<<j))!=(x&(1<<j))){
			cur^=(1<<j);
		}
	}





	cout<<"! ";
	for(llo i=0;i<n;i++){
		it[i]^=cur;
		cout<<it[i]<<" ";
	}
	cout<<endl;






	//llo val1






 
 
	return 0;
}