//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n;
vector<llo> pre[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<llo> pp;
	vector<llo> mm;
	llo co=0;
	for(llo i=2;i<=n;i++){
		llo st=1;
		for(llo j=2;j*j<=i;j++){
			if(i%j==0){
				st=0;
			}
		}
		if(st==1){
			if(i<=300){
				co+=1;
				mm.pb(i);
			}
			else{
				pp.pb(i);
			}
		}
	}
//	cout<<co<<endl;

	//cout<<pp.size()<<endl;
	//return 0;
	llo ans=1;
	llo cur=n;
	for(llo i=0;i<pp.size();i+=270){
		set<llo> cur2;
		set<llo> cur3;
		for(llo j=i;j<i+270 and j<pp.size();j++){
			cout<<"B "<<pp[j]<<endl;
			llo x;
			cin>>x;
			for(llo k=pp[j];k<=n;k+=pp[j]){
				llo stt=1;
				cur3.insert(k);
			}
		}
		cout<<"A "<<1<<endl;
		llo x;
		cin>>x;

		if(x!=cur-cur3.size()){
			for(llo j=i;j<i+270 and j<pp.size();j++){
				cout<<"A "<<pp[j]<<endl;
				llo xx;
				cin>>xx;
				if(xx==1){
					ans*=pp[j];
				}
			}
		}
		cur=x;
	}
	for(auto j:mm){
		cout<<"B "<<j<<endl;
		int x;
		cin>>x;
		cout<<"A "<<j<<endl;
		cin>>x;
		llo cot=j;
		while(x==1){
			ans*=j;
			
			cot*=j;
			if(cot>n){
				break;
			}
			cout<<"B "<<cot<<endl;
			cin>>x;
		}
	}
	cout<<"C "<<ans<<endl;










 
	return 0;
}