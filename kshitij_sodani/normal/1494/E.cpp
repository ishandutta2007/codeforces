//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n,m;
bool dist[200001][27][27];
int vis[2000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	map<pair<int,int>,int> ss;
	vector<pair<int,pair<int,int>>> qq;
	for(int i=0;i<m;i++){
		char s;
		cin>>s;
		if(s=='+'){
			int aa,bb;
			char sss;
			cin>>aa>>bb;
			aa--;
			bb--;
			cin>>sss;
			qq.pb({sss-'a'+1,{aa,bb}});
			ss[{aa,bb}]=0;
			ss[{bb,aa}]=0;
		}
		else if(s=='-'){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			qq.pb({-1,{aa,bb}});
		}
		else{
			int k;
			cin>>k;
			qq.pb({-1,{-1,(k-1)%2}});
		}
	}
	int co=0;
	int co2=0;
	for(auto j:qq){
		if(j.a>=0){
			int aa=j.b.a;
			int bb=j.b.b;

			ss[{aa,bb}]=j.a;
			
			if(ss[{aa,bb}]>0 and ss[{bb,aa}]>0){
				co2++;
			}
			if(ss[{aa,bb}]==ss[{bb,aa}]){
				co++;
			}
			/*if(ss[{bb,aa}]>0 and ss[{aa,bb}]>0){
				dist[aa][ss[{aa,bb}]][ss[{bb,aa}]]=1;
				dist[bb][ss[{aa,bb}]][ss[{bb,aa}]]=1;
			//	dist[aa][ss[{bb,aa}]][ss[{aa,bb}]]=1;
			//	dist[bb][ss[{bb,aa}]][ss[{aa,bb}]]=1;
			
			}
			co2-=vis[aa];
			vis[aa]=0;

			for(int i=1;i<27;i++){
				for(int j=i+1;j<27;j++){
					if(dist[aa][i][j]==1 and dist[aa][j][i]==1){
						vis[aa]=1;
						co2++;
						break;
					}
				}
			}
			co2-=vis[bb];
			vis[bb]=0;

			for(int i=1;i<27;i++){
				for(int j=i+1;j<27;j++){
					if(dist[bb][i][j]==1 and dist[bb][j][i]==1){
						vis[bb]=1;
						co2++;
						break;
					}
				}
			}*/

			
		}
		else if(j.b.a>=0){
			int aa=j.b.a;
			int bb=j.b.b;
			/*if(ss[{aa,bb}]>0 and ss[{bb,aa}]>0){
				dist[aa][ss[{aa,bb}]][ss[{bb,aa}]]=0;
				dist[bb][ss[{aa,bb}]][ss[{bb,aa}]]=0;
			//	dist[aa][ss[{bb,aa}]][ss[{aa,bb}]]=0;
			//	dist[bb][ss[{bb,aa}]][ss[{aa,bb}]]=0;
			}*/
			if(ss[{aa,bb}]>0 and ss[{bb,aa}]>0){
				co2--;
			}
			if(ss[{aa,bb}]==ss[{bb,aa}]){
				co--;
			}

			ss[{aa,bb}]=0;

			co2-=vis[aa];
			vis[aa]=0;

		/*	for(int i=1;i<27;i++){
				for(int j=i+1;j<27;j++){
					if(dist[aa][i][j]==1 and dist[aa][j][i]==1){
						vis[aa]=1;
						co2++;
						break;
					}
				}
			}
			co2-=vis[bb];
			vis[bb]=0;

			for(int i=1;i<27;i++){
				for(int j=i+1;j<27;j++){
					if(dist[bb][i][j]==1 and dist[bb][j][i]==1){
						vis[bb]=1;
						co2++;
						break;
					}
				}
			}*/


		}
		else{

			if(j.b.b==1){
				if(co>0){
					cout<<"YES"<<endl;
					continue;
				}
				else{
					cout<<"NO"<<endl;
					continue;
				}
				continue;
			}
			else{
				if(co>0 or co2>0){
					cout<<"YES"<<endl;
					continue;
				}
				else{
					cout<<"NO"<<endl;
				}

			}
		}
	}






 
	return 0;
}