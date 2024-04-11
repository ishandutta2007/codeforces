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
llo aa[100001];
llo cc[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo su=0;
	llo ans=0;
	vector<pair<llo,llo>> ss;
	for(llo i=0;i<n;i++){
		cin>>aa[i]>>cc[i];
		ans+=cc[i];
		ss.pb({aa[i],aa[i]+cc[i]});
	}
	sort(ss.begin(),ss.end());
	llo ind=0;
	vector<llo> pre;
	while(ind<ss.size()){
		llo cur=ind;
		llo ma=ss[ind].b;
		while(ind<ss.size()){
			if(ss[ind].a<=ma){
				ma=max(ma,ss[ind].b);
				ind++;
			}
			else{
				break;
			}
		}
		if(pre.size()){
			ans+=ss[cur].a-pre.back();
		}
		pre.pb(ma);
	
	}

	cout<<ans<<endl;










 
 
 
	return 0;
}