#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo l[101];
llo r[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,c,q;
		cin>>n>>c>>q;
		string s;
		cin>>s;
		vector<llo> ss;
		ss.pb(n);
		for(llo i=0;i<c;i++){
			cin>>l[i]>>r[i];
			ss.pb(ss.back()+r[i]-l[i]+1);
		}
		while(q--){
			llo k;
			cin>>k;
			for(llo i=c;i>=0;i--){
				//cout<<k<<":"<<endl;
				if(i==0){
					cout<<s[k-1]<<endl;
					break;
				}
				if(ss[i-1]>=k){
					continue;
				}
				k=((k-ss[i-1])+l[i-1]-1);
			}
		}
	}




	return 0;
}