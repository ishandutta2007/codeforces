//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo it[500001];
llo ind[500001];
llo pre[500001];
llo pre2[500001];
llo pre3[500001];
llo pre4[500001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,k;
	cin>>n>>k;
	vector<llo> cc;
	vector<llo> dd;
	llo pap=0;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		if(it[i]>0){
			cc.pb(it[i]);
			pap+=it[i];
		}
		else{
			dd.pb(it[i]);
		}
	}
	llo ans=0;
	vector<llo> ss;
	for(llo i=0;i<k+1;i++){
		ss.pb(0);
	}
	if(cc.size()){
		sort(cc.begin(),cc.end());
		reverse(cc.begin(),cc.end());
		for(llo i=0;i<cc.size();i++){
			ans+=cc[i]*((llo)cc.size()-i-1);
			ss[0]+=cc[i];
		}
	}
	if(dd.size()){
		sort(dd.begin(),dd.end());
	}

	llo ans2=-(llo)(1e18);
	if(dd.size()==0 or k==0){
		for(auto j:dd){
			if(k==0){
				ans+=ss[0]+ind[0]*j;
				ind[0]++;
			}
		}
		cout<<ans<<endl;

		return 0;
	}
	llo su=0;
	llo la=0;
	llo co=0;
	for(llo i=0;i<dd.size();i++){
		
		su+=dd[i];
		pre[i+1]=su;
		pre2[i+1]=co*(pre[i+1]-pre[la])+pre2[la];
		if((i+1)%(k+1)==0){
			la=i+1;
			co++;
		}
	}
	for(llo i=dd.size()-1;i>=0;i--){
		pre3[i]=pre3[i+1]+dd[i]*i;
		pre4[i]=pre4[i+1]+dd[i];
	}
	
	for(llo i=1;i<=dd.size();i++){
		llo cur=ans;
		llo tot=dd.size()-i;
		if((tot+k-1)/k>i){
			continue;
		}
		llo le=(tot+k-1)/k;
		tot+=(tot+k-1)/k;
	//	cout<<i<<":"<<tot<<endl;
	//	cout<<pre2[tot]<<",,"<<cur<<endl;
		cur+=pre2[tot];
		llo st=le;
		cur+=pre3[tot]+pre4[tot]*(st-tot);
		st+=dd.size()-tot;
		/*for(llo j=tot;j<dd.size();j++){
			cur+=dd[j]*st;
			st++;
		}*/
		cur+=st*pap;
		ans2=max(ans2,cur);
	}
	cout<<ans2<<endl;
 
 
	return 0;
}