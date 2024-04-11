#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

llo aa[5001];
llo bb[5001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,x,y;
		cin>>n>>x>>y;
		string s;
		string ss;
		cin>>s;
		cin>>ss;
		vector<llo> tt;
		for(llo i=0;i<n;i++){
			aa[i]=s[i]-'0';
		}
		for(llo i=0;i<n;i++){
			bb[i]=ss[i]-'0';
			if(aa[i]!=bb[i]){
				tt.pb(i);
			}
		}
		if(tt.size()%2==1){
			cout<<-1<<endl;
			continue;
		}
		if(tt.size()!=2){
			llo ans=(tt.size()/2)*y;
			cout<<ans<<endl;
		}
		else{
			if(tt[1]==tt[0]+1){
				cout<<min(2*y,x)<<endl;
			}
			else{
				cout<<y<<endl;
			}
		}

	}




	return 0;
}