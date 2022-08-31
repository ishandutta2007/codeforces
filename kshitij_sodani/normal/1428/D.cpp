
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int it[100001];
vector<pair<int,int>> ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	vector<pair<int,int>> aa;
	set<int> cur;
	for(int i=0;i<n;i++){
		cur.insert(i);
	}
	pair<int,int> pp={-1,-1};
	for(int i=n-1;i>=0;i--){
		if(it[i]==0){
			continue;
		}
		if(it[i]==1){
			auto j=cur.end();
			j--;
			aa.pb({i,*j});
			ans.pb({i,*j});
			cur.erase(j);
			
		}
		else if(it[i]==2){
			if(aa.size()==0){
				cout<<-1<<endl;
				return 0;
			}
			pair<int,int> xx=aa.back();
			aa.pop_back();
			ans.pb({i,xx.b});
			pp={i,xx.b};
		}
		else{
			if(pp.a==-1 and aa.size()==0){
				cout<<-1<<endl;
				return 0;
			}
			//connect i th column with pp
			pair<int,int> xx;
			if(pp.a==-1){
				xx=aa.back();
				aa.pop_back();
			}
			else{
				xx=pp;
			}
			auto j=cur.end();
			j--;
			ans.pb({i,*j});
			ans.pb({xx.a,*j});
			pp={i,*j};
			cur.erase(j);


			//change pp to current cell
		}
	}	

	cout<<ans.size()<<endl;
	for(auto j:ans){
		cout<<j.b+1<<" "<<j.a+1<<endl;
	}




	return 0;
}