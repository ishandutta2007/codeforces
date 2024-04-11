#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

llo it[100001];
llo pre[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,d,m;
	cin>>n>>d>>m;

	llo su=0;
	llo ans=0;
	llo st=1;
	vector<llo> aa;
	vector<llo> bb;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		if(it[i]<=m){
			su+=it[i];
			bb.pb(it[i]);
		}
		else{
			st=0;
			aa.pb(it[i]);
		}
	}
	ans=su;
	

	if(st){
		cout<<su<<endl;
		return 0;
	}
	sort(aa.begin(),aa.end());
	if(bb.size()){
		sort(bb.begin(),bb.end());
		for(int i=1;i<=bb.size();i++){
			pre[i]=pre[i-1]+bb[i-1];
		}
	}
	reverse(aa.begin(),aa.end());
	llo cur=0;
	for(int i=0;i<aa.size();i++){
		int x=n-i*d-i-1;
		cur+=aa[i];
		if(x<0){
			break;
		}
		if(aa.size()>=i*d+i+1){
			ans=max(ans,pre[bb.size()]+cur);
		}
		else{
			ans=max(ans,cur+pre[bb.size()]-pre[i*d-(aa.size()-i-1)]);
		}
	}
	cout<<ans<<endl;
	/*sort(it,it+n);
	llo cur2=ma;
	auto jj=cur.find(ma);
	cur.erase(ma);
	ans=max(ans,ma+su);
	while(cur.size()>=d+1){
		auto j=cur.end();
		j--;
		llo de=*j;
		if(de<=m){
			break;
		}
		cur.erase(j);
		cur2+=de;
	//	cout<<de<<endl;
		vector<llo> kc;
		for(int i=0;i<d;i++){
			auto j=cur.end();
			j--;
			if(*j<=m){
				break;
			}
			kc.pb(*j);
			cur.erase(j);
		}
		for(int i=kc.size();i++){

		}
		llo val3=cur2+su;

		for(llo i=0;i<d;i++){
			llo xx=*(cur.begin());
	//		cout<<xx<<":";
			if(xx<=m){
				su-=xx;
			}
			cur.erase(cur.begin());
		}
	//	cout<<endl;
		ans=max(ans,cur2+su);
	//	cout<<cur2+su<<"/"<<endl;
	}
	ans=max(ans,cur2+su);
	cout<<ans<<endl;

	
	
*/
	return 0;
}