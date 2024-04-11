//#pragma GCC optimize("Ofast,unroll-loops")
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
	int q;
	cin>>q;
	while(q--){
		string s;
		string t;
		cin>>s>>t;
		string ans="";
		int st=1;
		for(int i=0;i<100;i++){
			ans+=t;
			int kk=1;
			if((ans.size())%(s.size())!=0){
				kk=0;
			}
			for(int j=0;j<ans.size();j++){
				if((ans[j]!=s[j%(s.size())])){
					kk=0;
				}
			}
			if(kk==1){
				cout<<ans<<endl;
				st=0;
				break;
			}
		}
		if(st==1){
			cout<<-1<<endl;
			continue;
		}
	}

 
 
	
 
	return 0;
}