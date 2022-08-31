//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n;
int it[1001];
int ans[1001][1001];
int co[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<int,int>> ss;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
		ss.pb({it[i],i});
	}
	sort(ss.begin(),ss.end());
//	reverse(ss.begin(),ss.end());
	//int pre=-1;
	//set<int> le;
 	for(int i=0;i<n;i++){

 		/*if(i>0){
 			int st=0;
 			for(int j=0;j<n;j++){
 				st+=ans[i][j];
 			}
 			if(st==0){



 				continue;
 			}
 		}*/
 		int cot=0;
 		//int pp=i+1;
 		int pp=i;
 		/*if(i==0){
 			pp=0;
 		}*/
 		for(int j=0;j<min(ss[i].a,i+1);j++){
 			ans[pp][ss[i].b]=1;
 			co[pp]+=1;
 			//cout<<pp<<":";
 			pp--;
 		/*	if(co[j]==1){
 				cot+=1;
 			}*/
 		}
 		//cout<<endl;
 		for(int j=0;j<i;j++){
 			if(ss[j].a>=i+1){
 				ans[i+1][ss[j].b]=1;
 			}
 		}
 	/*	int st=0;
 		for(int j=0;j<n;j++){
 			st|=(ans[i][j]^ans[i+1][j]);
 		}
 		if(st==0){
 			auto j=le.end();
 			j--;
 			int jj=*j;
 			ans[0][ss[jj].b]=0;
 			ans[i][ss[jj].b]=1;
 			le.erase(j);
 		}
 		else{
 			pre=cur;
 		}
		le.insert(i); 	*/	
 		
 	}


 	//vector<int> ss;
 	vector<int> tt;
 	vector<int> pp;

 	for(int i=0;i<n+1;i++){
 		int su=0;
 		for(int j=0;j<n;j++){
 			su+=ans[i][j];
 		}
 		if(su>0){
 			tt.pb(i);
 		}
 	}
 
 	cout<<tt.size()<<endl;

 	for(auto i:tt){
 		for(int j=0;j<n;j++){
 			cout<<ans[i][j];
 		}
 		cout<<endl;
 	}
 
 
 
 
 
	return 0;
}