//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int co[30];
int ans[100001];
int vis[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	string ss="abcdefghijklmnopqrstuvwxyz";
	//cout<<ss.size()<<endl;
	//return 0;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		int st=1;
		for(int i=0;i<30;i++){
			co[i]=0;
		}
		for(int i=0;i<n;i++){
			vis[i]=0;
		}
		for(int i=0;i<n;i++){
			if(s[i]!=s[0]){
				st=0;
			}
			co[s[i]-'a']++;
		}
		if(st==1){
			cout<<s<<endl;
			continue;
		}
		st=-1;
		vector<int> tt;
		for(int i=0;i<30;i++){

			if(co[i]>0){
				tt.pb(i);
			}
		}
		for(int i=0;i<30;i++){
			if(co[i]==1){
				st=i;
				break;
			}
		}
		//cout<<st<<":"<<endl;
		if(st>=0){
			//answer is 0 
			//easy
			//string ans="";
			vector<int> kk;
			ans[0]=st;
			int ind=1;
			for(int i=0;i<tt.size();i++){
				if(tt[i]!=st){
					for(int j=0;j<co[tt[i]];j++){
						ans[ind]=tt[i];
						ind++;
					}
				}
				
			}
				for(int i=0;i<n;i++){
					cout<<ss[ans[i]];
				}
				cout<<endl;
		}
		else{
			//answer is 1
			if(co[tt[0]]-2<=((n-2)/2)){
				ans[0]=tt[0];
				ans[1]=tt[0];
				vis[0]=1;
				vis[1]=1;
				int le=co[tt[0]]-2;
				int ind=3;

				while(le>0){

					ans[ind]=tt[0];
					le--;
					vis[ind]=1;
					ind+=2;
				}

				vector<int> kk;
				for(int i=1;i<tt.size();i++){
					for(int j=0;j<co[tt[i]];j++){
						kk.pb(tt[i]);
					}
				}
				reverse(kk.begin(),kk.end());

				for(int i=0;i<n;i++){
					if(vis[i]==0){
						vis[i]=1;
						ans[i]=kk.back();
						kk.pop_back();
					}
				}

				for(int i=0;i<n;i++){
					cout<<ss[ans[i]];
				}
				cout<<endl;
			}
			else if(tt.size()==2){
				ans[0]=tt[0];
				ans[1]=tt[1];
				vis[0]=1;
				vis[1]=1;

				vector<int> kk;
				for(int ii=0;ii<tt.size();ii++){
					int i=ii;
					if(ii<=1){
						i^=1;
					}
					//cout<<i<<":"<<endl;
					for(int j=0;j<co[tt[i]];j++){
						kk.pb(tt[i]);
					}
					if(i<=1){
						kk.pop_back();
					}
				}
				reverse(kk.begin(),kk.end());
				for(int i=0;i<n;i++){
					if(vis[i]==0){
						ans[i]=kk.back();

						kk.pop_back();
						vis[i]=1;
					}
				}
				for(int i=0;i<n;i++){
					cout<<ss[ans[i]];
				}
				cout<<endl;

			}
			else{
				ans[0]=tt[0];
				ans[1]=tt[1];
				vis[0]=1;
				vis[1]=1;

				vector<int> kk;
				for(int ii=0;ii<tt.size();ii++){
					int i=ii;
					/*if(ii<=1){
						i^=1;
					}*/
					//cout<<i<<":"<<endl;
					for(int j=0;j<co[tt[i]];j++){
						kk.pb(tt[i]);
					}
					if(i<=1){
						kk.pop_back();
					}
					if(i==0){
						kk.pb(tt[2]);
						co[tt[2]]--;
					}
					
				}
				reverse(kk.begin(),kk.end());
				for(int i=0;i<n;i++){
					if(vis[i]==0){
						ans[i]=kk.back();

						kk.pop_back();
						vis[i]=1;
					}
				}
				for(int i=0;i<n;i++){
					cout<<ss[ans[i]];
				}
				cout<<endl;
			}


		}






	}
 
 
 
 
 
 
 
	return 0;
}