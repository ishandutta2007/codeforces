#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;
llo aa[100001];
llo bb[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	llo n;
	cin>>n;
	vector<pair<llo,llo>> cc;
	//llo ans=0;
	//llo su=0;
	pair<llo,llo> ma={-1,-1};
	for(llo i=0;i<n;i++){
		cin>>aa[i]>>bb[i];
		//ans+=2*aa[i];
		//su+=2*aa[i];
		//ma=max(ma,{aa[i],bb[i]});
		cc.pb({bb[i],aa[i]});
	}
	sort(cc.begin(),cc.end());
	//llo kk=0;
	//llo st=1;

	for(llo i=0;i<n;i++){
		/*if(aa[i]==ma.a and bb[i]==ma.b and st==1){
			st=0;
			continue;
		}*/
		//kk+=aa[i];
	}
	llo cur=0;
	llo ans=0;
	llo su=0;
	for(int i=0;i<n;i++){
		//ans+=aa[i]*2;
		su+=aa[i];
	}
	llo l=0;
	llo r=n-1;
	//llo cur=0;
	while(l<=r){
		//cout<<l<<":"<<r<<endl;
		if(cc[l].b==0){
			l++;
		}
		else if(cc[r].b==0){
			r--;
		}
		else{
			if(cc[l].a<=cur){
				ans+=cc[l].b;
				//l++;

				cur+=cc[l].b;
				cc[l].b=0;
				continue;
			}
			llo mi=min(cc[l].a-cur,cc[r].b);
			ans+=2*mi;
			cur+=mi;
			cc[r].b-=mi;

		}
		//cout<<ans<<":"<<endl;
	}
	cout<<ans<<endl;
	return 0;
	reverse(cc.begin(),cc.end());
	for(auto i:cc){
		llo cot=2*max(i.a,cur);
		cot+=(su-max(i.a-cur,(llo)0));
		ans=min(ans,cot);
		/*if(i.a>cur){

		}
		else{

		}*/



		cur+=i.b;
		/*if(i.a>cur){
			llo le=min(i.a-cur,i.b);
			cur+=le;
			ans+=2*le;
			ans+=(i.b-le);
			cur+=(i.b-le);
		}
		else{
			cur+=i.b;
			ans+=i.b;
		}*/

	}
	
	cout<<ans<<endl;








	return 0;
}