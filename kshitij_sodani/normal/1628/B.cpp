//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;
string ss[100001];
int st=1;
int n;
set<int> zz[26];
void solve(){
	map<string,int> tt;
	for(int i=0;i<26;i++){
		zz[i].clear();
	}
	map<string,int> yy;
	for(int j=0;j<n;j++){

		if(ss[j].size()==1){
			zz[ss[j][0]-'a'].insert(j);
		}
		string xx=ss[j];

		reverse(xx.begin(),xx.end());
		if(tt.find(xx)!=tt.end()){
			st=0;
		}
		if(xx.size()>1){
			string ac="";
			for(int i=0;i+1<xx.size();i++){
				ac+=xx[i];
			}
			
			if(tt.find(ac)!=tt.end()){
				st=0;
			}
		}


		tt[ss[j]]++;
		if(ss[j].size()==3){
			if(zz[ss[j][2]-'a'].size()>0){
				if(ss[j][0]==ss[j][1]){
					st=0;
				}
				if(zz[ss[j][1]-'a'].size()>0){
					auto jj=(zz[ss[j][1]-'a']).end();
					jj--;
					if((*jj)>*(zz[ss[j][2]-'a'].begin())){
						st=0;
					}
				}
				int ind=*(zz[ss[j][2]-'a'].begin());
				string kk="";//ss[j][2]+ss[j][1];
				kk+=ss[j][1];
				kk+=ss[j][0];
				if(yy.find(kk)!=yy.end()){
					
					if(yy[kk]>ind){
						st=0;
					}
				}
			}
		}
		if(xx.size()==2){
			yy[ss[j]]=j;
		}
		if(xx.size()==3){
			string ac="";
			for(int i=0;i+1<ss[j].size();i++){
				ac+=ss[j][i];
			}
			yy[ac]=j;
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		
		cin>>n;
		st=1;
		for(int i=0;i<n;i++){
			cin>>ss[i];
			int ok=1;
			int zz5=ss[i].size();
			for(int j=0;j<ss[i].size();j++){
				if(ss[i][j]==ss[i][zz5-1-j]){

				}
				else{
					ok=0;
				}
			}
			if(ok){
				st=0;
			}
		}
		
		solve();
		for(int i=0;i<n/2;i++){
			swap(ss[i],ss[n-i-1]);
		}
		for(int i=0;i<n;i++){
			string xx=ss[i];
			reverse(xx.begin(),xx.end());
			ss[i]=xx;
		}
		solve();
		if(st==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}




 
	return 0;
}