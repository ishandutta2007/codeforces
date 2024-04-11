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
llo n;
llo ans;
llo check(llo aa){
	llo cc=0;
	for(llo i=0;i<n;i++){
		llo dd=aa-(it[i]%aa);
		if(it[i]>=aa){
			dd=min(dd,it[i]%aa);
		}
		cc+=dd;
	}
	return cc;
}
void re(llo x){
	if(x==0){
		return ;
	}
	vector<llo> cur;
	llo cot=x;
	while(cot>1){
		llo ind=cot;
		for(llo i=2;i*i<=cot;i++){
			if(cot%i==0){
				ind=i;
				break;
			}
		}
		ans=min(ans,check(ind));
		while(cot%ind==0){
			cot/=ind;
		}
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	ans=check(2);
 	mt19937 rng;
 	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());
 	for(llo ii=0;ii<20;ii++){
 		llo i=rng()%n;
 		re(it[i]);
 		re(it[i]-1);
 		re(it[i]+1);
 	}


 	cout<<ans<<endl;


 
	return 0;
}