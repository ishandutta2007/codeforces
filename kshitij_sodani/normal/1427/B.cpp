
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int ans=0;
		int co=0;

		int ind=-1;
		int ind2=-1;
		for(int i=0;i<n;i++){
			if(s[i]=='L'){
				co+=1;
			}
			else{
				if(ind==-1){
					ind=i;
				}
				ind2=i;
			}
		}
		if(co==n){
			if(k==0){
				cout<<0<<endl;
				continue;
			}
			cout<<2*k-1<<endl;
			continue;
		}
		co=max(0,co-k);
		ans+=2*co;
		vector<int> cc;
		int cot=0;
		ans+=1;
		for(int i=ind+1;i<=ind2;i++){
			if(s[i]=='L'){
				cot+=1;
			}
			else{
				if(cot>0){
					ans+=1;
					cc.pb(cot);
				}
				
				cot=0;
			}
		}

		sort(cc.begin(),cc.end());
		int le=k;
		for(auto j:cc){
			if(j<=le){
				le-=j;
				ans-=1;
			}
		}
		cout<<2*n-ans<<endl;




	}



	return 0;
}