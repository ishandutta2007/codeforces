//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n;
llo it[5001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	//n=5000;
	while(t--){
		cin>>n;
		//llo su=0;
		llo ind=0;
		llo ans=0;
		set<int> cot;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			//it[i]=5000;
			if(it[i]>1){
				cot.insert(i);
			}
			//su+=it[i];
		/*	if(it[i]>5000){
				ans+=it[i]-5000;
				it[i]=5000;
			}*/
		}
		


		while(true){
			llo st=1;
			while(ind<n){
				if(it[ind]==1){
					ind++;
				}
				else{
					break;
				}
			}
			if(ind==n){
				break;
			}

			if(it[ind]>n){
				ans+=it[ind]-n;
				it[ind]=n;
				continue;
			}

			llo cur=ind;
			while(cur<n){
				llo cur2=it[cur]+cur;

				it[cur]--;
				if(it[cur]==0){
					it[cur]++;
				}
				if(it[cur]==1){
					cot.erase(cur);
				}
				auto j=cot.lower_bound(cur2);
				if(j!=cot.end()){
					cur=(*j);
				}
				else{
					break;
				}
				//cur=cur2;
			}
			ans++;
		}


		cout<<ans<<endl;

	}






 
	return 0;
}