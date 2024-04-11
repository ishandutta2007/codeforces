#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n;
int ans[301][301];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans[i][j]=0;
			}
		}
		int x=k/n;
		int y=k%n;
		set<pair<int,int>> cur;
		vector<pair<int,int>> kk;
		for(int i=0;i<n;i++){
			cur.insert({0,i});
		}
		for(int i=0;i<n;i++){
			int val=x;
			if(i>=n-y){
				val+=1;
			}
			for(int j=0;j<val;j++){
				pair<int,int> no=*(cur.begin());
				cur.erase(no);
				ans[i][no.b]=1;
				kk.pb({no.a+1,no.b});
			}
			for(auto j:kk){
				cur.insert(j);
			}
			kk.clear();
		}
		int ans2=0;
		if(y>0){
			ans2=1;
		}
		int ma=0;
		int mi=n;
		for(int i=0;i<n;i++){
			int x=0;
			for(int j=0;j<n;j++){
				x+=ans[j][i];
			}
			ma=max(ma,x);
			mi=min(mi,x);
		}
		cout<<ans2+(ma-mi)*(ma-mi)<<endl;
	//	cout<<ans2<<":"<<ma<<":"<<mi<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<ans[i][j];
			}
			cout<<endl;
		}

	}



	return 0;
}