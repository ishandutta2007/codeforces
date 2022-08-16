//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo t;
llo aa[100001];
llo bb[100001];
llo co[2][2];
llo cur[2][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		string s;
		cin>>s;
		string ss;
		cin>>ss;
		for(llo i=0;i<2;i++){
			for(llo j=0;j<2;j++){
				co[i][j]=0;
			}
		}
		llo ans=-1;
		for(llo i=0;i<n;i++){
			aa[i]=s[i]-'0';
		}
		for(llo i=0;i<n;i++){
			bb[i]=ss[i]-'0';
			co[aa[i]][bb[i]]++;
		}
		if(co[0][1]==co[1][0]){
			ans=2*co[0][1];
		}
		if(co[1][1]==co[0][0]+1){
			if(ans==-1){
				ans=co[1][1]+co[0][0];
			}
			ans=min(ans,co[1][1]+co[0][0]);
		}

		cout<<ans<<endl;
 
 
	}
 
 
 
 
 
 
 
	return 0;
}