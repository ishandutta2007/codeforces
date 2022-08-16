#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int aa,bb,cc,dd;
		cin>>aa>>bb>>cc>>dd;
		string s;
		cin>>s;
		int co=0;
		int co2=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='A'){
				co++;
			}
			else{
				co2++;
			}
		}
		if(co!=aa+cc+dd){
			cout<<"NO"<<endl;
			continue;
		}
		else if(co2!=bb+cc+dd){
			cout<<"NO"<<endl;
			continue;
		}
		vector<pair<int,int>> kk2;
		for(int i=0;i<s.size();i++){
			int j=s[i]-'A';
			if(i==0){
				kk2.pb({j,1});
			}
			else{
				if(s[i]==s[i-1]){
					kk2.pb({j,1});
				}
				else{
					kk2[kk2.size()-1].b+=1;
				}
			}
		}
		int su=0;
		multiset<pair<int,int>> kk;
		multiset<pair<int,int>> mm;
		for(auto j:kk2){
			if(j.b==1){
				continue;
			}
			if(j.a==0){
				kk.insert({j.b%2,j.b});
			}
			else{
				mm.insert({j.b%2,j.b});
			}
		}
		while(cc>0){
			if(kk.size()){
				auto j=kk.begin();
				if(j==kk.end()){
					break;
				}
				cc--;
				pair<int,int> no=(*j);
				kk.erase(j);
				if(no.b-2>1){
					kk.insert({no.a,no.b-2});
				}
			}
			else{
				break;
			}
		}
		while(dd>0){
			if(mm.size()){
				auto j=mm.begin();
				if(j==mm.end()){
					break;
				}
				dd--;
				pair<int,int> no=(*j);
				mm.erase(j);
				if(no.b-2>1){
					mm.insert({no.a,no.b-2});
				}
			}
			else{
				break;
			}
		}
		if(cc==0 and dd==0){
			cout<<"YES"<<endl;
		}
		else if(cc>0 and dd>0){
			cout<<"NO"<<endl;
		}
		else{
			if(cc>0){
				int ok=0;
				for(auto j:mm){
					ok+=((j.b-1)/2);
				}
				if(ok<cc){
					cout<<"NO"<<endl;
				}
				else{
					cout<<"YES"<<endl;
				}
			}
			else{
				int ok=0;
				for(auto j:kk){
					ok+=((j.b-1)/2);
				}
				if(ok<dd){
					cout<<"NO"<<endl;
				}
				else{
					cout<<"YES"<<endl;
				}
			}
		}

	}









	return 0;
}