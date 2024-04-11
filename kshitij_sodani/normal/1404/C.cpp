
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
llo n,q;
llo it[310001];
llo pre[310001];

llo tree[310001];
void u(llo i,llo j){
	while(i<310001){
		tree[i]+=j;
		i+=(i&-i);
	}
}
llo ss(llo i){
	llo su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}
llo ans[310001];
vector<pair<llo,llo>> pre2[310001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		it[i]-=(i+1);
	}
	for(llo i=0;i<q;i++){
		llo aa,bb;
		cin>>aa>>bb;
		pre2[n-bb-1].pb({aa,i});
	}
	for(llo i=0;i<n;i++){
		if(it[i]<=0){
			if(ss(1)>=-it[i]){
				llo low=0;
				llo high=i;
				while(low<high-1){
					llo mid=(low+high)/2;
					if(ss(mid+1)>=-it[i]){
						low=mid;
					}
					else{
						high=mid;
					}
				}
				llo ind=low;
				if(ss(high+1)>=-it[i]){
					ind=max(ind,high);
				}
				u(1,1);
				u(ind+2,-1);
			}

		}
		/*for(llo j=0;j<=i;j++){
			cout<<ss(j+1)<<',';
		}
		cout<<endl;*/
		for(auto j:pre2[i]){
		//	cout<<i<<":"<<j.a<<":"<<j.b<<endl;
			ans[j.b]=ss(j.a+1);
		}

		/*for(llo j=0;j<=i;j++){
			if(it[i]>0){
				continue;
			}
			if(pre[j]>=-it[i]){
				pre[j]+=1;
			}
		}

		for(llo j=0;j<=i;j++){
			cout<<pre[j]<<",";
		}
		cout<<endl;*/
	}
	for(llo i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	



	return 0;
}