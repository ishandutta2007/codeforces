

#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		llo aa,bb;
		llo cc,dd;

		cin>>aa>>bb;
		cin>>cc>>dd;
		if(aa>cc){
			swap(aa,cc);
			swap(bb,dd);
		}

		llo st=0;
		llo tt=0;
		if(bb>=cc){
			st=0;
			k-=n*(min(bb,dd)-cc);
			k=max(k,(llo)0);
		}
		else{
			st=cc-bb;
		}
		if(k==0){
			cout<<0<<'\n';
			continue;
		}
		llo ans=1e15;
		llo cost=0;
		llo cur=0;
		llo val=(max(bb,dd)-min(aa,cc));//;

		llo ko=val*2-(bb-aa)-(dd-cc);
		val-=max((llo)0,min(bb,dd)-max(aa,cc));
		//cout<<ko<<":"<<val<<endl;
		for(llo i=1;i<=n;i++){
			if(cur+val>=k){
				ans=min(ans,cost+st+k-cur);
				break;
			}
			cur+=val;
			cost+=ko;
			ans=min(ans,cost+2*(k-cur));
		}
		cout<<ans<<'\n';
	}


	return 0;
}