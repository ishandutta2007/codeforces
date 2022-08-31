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
int it[501];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	//vector<pair<int,int>> ss;
	for(int i=0;i<n;i++){
		cin>>it[i];
		//ss.pb({it[i],i});
	}
	//sort(ss.begin(),ss.end());
	vector<pair<int,pair<int,int>>> tt;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int aa=i;
			int bb=j;
			if(it[i]>it[j]){
				swap(aa,bb);
			}
			//aa<bb
			tt.pb({abs(it[i]-it[j]),{aa,bb}});

		}
	}
	sort(tt.begin(),tt.end());
	reverse(tt.begin(),tt.end());
	for(auto j:tt){
		//cout<<it[j.b.a]<<":"<<it[j.b.b]<<endl;
		//ask from more indegree to less indegree

		cout<<"? "<<j.b.b+1<<" "<<j.b.a+1<<endl;
		string x;
		cin>>x;
		if(x=="Yes"){
			cout<<"! "<<j.b.b+1<<" "<<j.b.a+1<<endl;
			return 0;
		}

	}
	cout<<"! 0 0"<<endl;









 
	return 0;
}