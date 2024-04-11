//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		//set<llo> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		//	ss.insert(it[i]);
		}
		llo x=0;
		vector<llo> ss;
		for(llo i=1;i<n;i++){
			ss.pb(abs(it[i]-it[i-1]));
		}

		//sort(ss.begin(),ss.end());
		llo ans=0;
		for(llo i=0;i<n-1;i++){
			ans+=ss[i];
		}
		llo ma=0;
		for(llo i=0;i<n;i++){
			llo cur=0;
			if(i>0 and i<n-1){
				cur+=ss[i]+ss[i-1];
				cur-=abs(it[i-1]-it[i+1]);
			}
			else if(i==0){
				cur=abs(it[i]-it[i+1]);
			}
			else{

				cur=abs(it[n-1]-it[n-2]);
			}

			ma=max(ma,cur);
		}
		ans-=ma;
		cout<<ans<<endl;


	}






 
 
	return 0;
}