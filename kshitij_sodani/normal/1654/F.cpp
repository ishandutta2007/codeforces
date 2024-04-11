#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int it[1<<18];
int ind[1<<18];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<pair<int,int>> ee;
	for(int i=0;i<(1<<n);i++){
		it[i]=s[i]-'a';
		ee.pb({it[i],i});
	}
	sort(ee.begin(),ee.end());
	int cur=0;
	int xx=-1;
	for(auto j:ee){
		if(j.a!=xx){
			xx=j.a;
			cur++;
			
		}
		ind[j.b]=cur;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		vector<pair<pair<int,int>,int>> ss;
		for(int j=0;j<(1<<n);j++){
			ss.pb({{ind[j],ind[j^(1<<(i-1))]},j});
		}
		sort(ss.begin(),ss.end());
		pair<int,int> yy={-1,-1};
		cur=0;
		for(auto j:ss){
			if(j.a!=yy){
				yy=j.a;
				cur++;
			}
			ind[j.b]=cur;
			if(i==n and cur==1){
				ans=j.b;
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		cout<<s[i^ans];
	}
	cout<<endl;





	return 0;
}