//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo val[200001];
llo aa[200001];
llo bb[200001];
llo vis[1000001];
llo val2[1000001];
llo co[200001];
llo pre[200001];
llo pre2[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	for(llo i=0;i<n;i++){
		cin>>bb[i];
	}
	for(llo i=1;i<=1000000;i++){
		val2[i]=1;
	}
	for(llo i=2;i<=1000000;i++){
		if(vis[i]==0){
			for(llo j=i;j<=1000000;j+=i){
				val2[j]*=i;
				vis[j]++;
			}
		}
	}
	for(llo i=1;i<=200000;i++){
		if(i==1){
			co[i]=1;
		}
		else if(val2[i]<i){
			co[i]=0;
		}
		else{
			if(vis[i]%2==1){
				co[i]=-1;
			}
			else{
				co[i]=1;
			}
		}
	}
	llo cot=0;
	vector<llo> aaa;
	//cout<<n<<endl;
	for(llo i=1;i<n;i++){
		val[i]+=bb[i]-aa[i];
		if(co[i+1]==0){
			cot+=abs(val[i]);
		}
		if(co[i+1]==-1){
			aaa.pb(val[i]);
		}
		else if(co[i+1]==1){
			aaa.pb(-val[i]);
		}
		for(llo j=i+(i+1);j<n;j+=(i+1)){
		//	cout<<i<<":"<<j<<endl;
			val[j]-=val[i];
			//aa[j]+=val[i];
		}
	}
	//return 0;
	sort(aaa.begin(),aaa.end());
	for(llo i=1;i<=aaa.size();i++){
		pre[i]=pre[i-1]+aaa[i-1];

	}


	llo q;
	cin>>q;
	while(q--){
		llo x;
		cin>>x;
		llo ans=abs(x-aa[0])+cot;

		if(aaa.size()){
			llo ind=lower_bound(aaa.begin(),aaa.end(),(x-aa[0]))-aaa.begin();
			if(aaa.back()<=(x-aa[0])){
				ind=aaa.size();
			}

			ans+=abs(pre[ind]-(x-aa[0])*ind);
			//cout<<ans<<"::"<<endl;
			ans+=abs((pre[aaa.size()]-pre[ind])-(x-aa[0])*(aaa.size()-ind));
		}
		
		cout<<ans<<endl;
	}



 
	return 0;
}