//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[100001];
map<llo,llo> ss;
void run(llo l,llo r){
	llo su=0;
	for(llo i=l;i<=r;i++){
		su+=it[i];
	}
	ss[su]++;
//	cout<<l<<":"<<r<<endl;
	//cout<<su<<":";
	if(l<r){
		llo mid=(it[l]+it[r])/2;
		llo ind=l;
		for(llo j=19;j>=0;j--){
			if(ind+(1<<j)<=r){
				if(it[ind+(1<<j)]<=mid){
					ind+=(1<<j);
				}
			}
		}
		if(ind<r){
			run(l,ind);
			run(ind+1,r);
		}

	}


}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,q;
		cin>>n>>q;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		sort(it,it+n);
		ss.clear();
		run(0,n-1);

		//cout<<endl;



		while(q--){
			llo aa;
			cin>>aa;
			if(ss.find(aa)!=ss.end()){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
	}









 
	return 0;
}