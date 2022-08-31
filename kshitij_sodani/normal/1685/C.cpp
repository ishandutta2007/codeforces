#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int t;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		
		int su=0;
		int st=1;
		vector<int> tt;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				su++;
			}
			else{
				su--;
			}
			if(su<0){
				st=0;
				tt.pb(i);
			}
		}
		if(st==1){
			cout<<0<<endl;
			continue;
		}
		pair<int,int> mi={0,0};
		int su2=0;
		for(int i=tt[0];i>=0;i--){
			if(s[i]=='('){
				su2++;
			}
			else{
				su2--;
			}
			mi=min(mi,{su2,i});
		}
		pair<int,int> ma={-1e9,1e9};
		int su3=0;
		for(int i=tt.back();i<s.size();i++){
			if(s[i]=='('){
				su3++;
			}
			else{
				su3--;
			}
			ma=max(ma,{su3,i});
		}
		string ss="";
		for(int i=0;i<mi.b;i++){
			ss+=s[i];
		}
		for(int i=ma.b;i>=mi.b;i--){
			ss+=s[i];
		}
		for(int i=ma.b+1;i<s.size();i++){
			ss+=s[i];
		}
		su=0;
		st=1;
		for(int i=0;i<ss.size();i++){
			if(ss[i]=='('){
				su++;
			}
			else{
				su--;
			}
			if(su<0){
				st=0;
			}
		}
		if(st==1){
			cout<<1<<endl;
			cout<<mi.b+1<<" "<<ma.b+1<<endl;
			continue;
		}
		ma={-1,-1};
		su=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				su++;
			}
			else{
				su--;
			}
			ma=max(ma,{su,i});
		}
		cout<<2<<endl;
		cout<<1<<" "<<ma.b+1<<endl;
		cout<<ma.b+2<<" "<<s.size()<<endl;


	}


 
 
 
 
	return 0;
}