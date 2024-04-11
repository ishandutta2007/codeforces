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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		multiset<int> xx;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			xx.insert(x);
		}
		int ans=0;
		int st=1;
		for(int i=n;i>=1;i--){
			if(xx.find(i)!=xx.end()){
				auto j=xx.find(i);
				xx.erase(j);
				continue;
			}
			auto j=xx.end();
			j--;
			int y=(*j);
			if(i>=((y+1)/2)){
				st=0;
				break;
			}
			ans++;
			xx.erase(j);
		}
		if(st==0){
			cout<<-1<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}





 
	return 0;
}