//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo aa,bb,cc;
	cin>>aa>>bb>>cc;
	vector<pair<llo,llo>> ss;
	cout<<"First"<<endl;
	ss.pb({aa,0});
	ss.pb({bb,1});
	ss.pb({cc,2});
	llo x;
	if(true){
		sort(ss.begin(),ss.end());
		x=ss.back().a*2-ss[0].a-ss[1].a;
		cout<<x<<endl;
	}
	llo y;
	cin>>y;

	for(llo i=0;i<3;i++){
		if(ss[i].b==y-1){
			ss[i].a+=x;
		}
	}
	if(y==ss.back().b+1){
		sort(ss.begin(),ss.end());
		llo xi=ss.back().a*2-ss[0].a-ss[1].a;
		cout<<xi<<endl;
		llo yy;
		cin>>yy;

		for(llo i=0;i<3;i++){
			if(ss[i].b==yy-1){
				ss[i].a+=xi;
			}
		}
		if(true){
			sort(ss.begin(),ss.end());
			llo xx=ss[0].a-ss[1].a;
			cout<<-xx<<endl;
		}

	}
	else{
		sort(ss.begin(),ss.end());
		llo xx=ss[0].a-ss[1].a;
			cout<<-xx<<endl;
	}
	

	








 
	return 0;
}