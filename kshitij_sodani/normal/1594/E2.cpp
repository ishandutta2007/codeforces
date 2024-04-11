//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo dp[61*2000][6];
llo pre[61];
llo dp2[61][6];

const llo mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	pre[0]=1;
	for(llo i=1;i<=n;i++){
		pre[i]=(pre[i-1]*2)%mod;
	}

	for(llo i=0;i<6;i++){
		dp2[0][i]=1;
	}
	for(llo i=1;i<n;i++){
		for(llo j=0;j<6;j++){
			for(llo l=0;l<6;l++){
				for(llo m=0;m<6;m++){
					if(j==l or j==m ){
						continue;
					}
					if((j^1)==l or (j^1)==m){
						continue;
					}
					dp2[i][j]=(dp2[i][j]+dp2[i-1][l]*dp2[i-1][m])%mod;
				}
			}
		}
	}

	llo k;
	cin>>k;
	set<pair<llo,llo>> kk;
	map<llo,llo> ind;
	map<llo,llo> req;
	//llo req;
	llo cot2=0;
	for(llo i=0;i<k;i++){
		llo x;
		llo cot;
		cin>>x;
		string s;
		cin>>s;
		if(s=="white"){
			cot=0;
		}
		else if(s=="yellow"){
			cot=1;
		}
		else if(s=="green"){
			cot=2;
		}
		else if(s=="blue"){
			cot=3;
		}
		else if(s=="red"){
			cot=4;
		}
		else if(s=="orange"){
			cot=5;
		}
		req[x]=cot;
		vector<llo> ss;
		while(x>0){
			ss.pb(x);
			x/=2;
		}

		reverse(ss.begin(),ss.end());
		for(llo j=0;j<ss.size();j++){

			if(ind.find(ss[j])==ind.end()){
				ind[ss[j]]=cot2;
				cot2++;
			}
			kk.insert({-(j),ss[j]});
		}
	}
	/*cout<<cot2<<",,"<<endl;

	for(auto j:req){
		cout<<j.a<<"?"<<j.b<<endl;
	}*/
	for(auto j:kk){
		pair<llo,llo> no=j;
		no.a=-no.a;
	//	cout<<no.b<<":"<<no.a<<endl;
		llo ind2=ind[no.b];
		llo ind3=-1;
		llo ind4=-1;
		if(ind.find(no.b*2+0)!=ind.end()){
			ind3=ind[no.b*2+0];
		}
		if(ind.find(no.b*2+1)!=ind.end()){
			ind4=ind[no.b*2+1];
		}
		//cout<<ind3<<"::"<<ind4<<endl;
		llo rr=-1;
		if(req.find(j.b)!=req.end()){
			rr=req[j.b];
		}
		//cout<<rr<<endl;
		if(ind3==-1 and ind4==-1){
			for(int i=0;i<6;i++){
				if(rr==i){
					dp[ind2][i]=dp2[n-1-no.a][i];
				}
			}
			continue;
		}
	/*	if(no.a==n-1){
		//	cout<<11<<endl;
			dp[ind2][rr]=1;
			continue;
		}*/


		for(llo i=0;i<6;i++){
			if(rr>=0 and rr!=i){
				continue;
			}
			for(llo l=0;l<6;l++){
				for(llo m=0;m<6;m++){
					llo pro=1;

					if(i==l or i==m ){
						continue;
					}
					if((i^1)==l or (i^1)==m){
						continue;
					}

					if(ind3==-1){
						pro=dp2[n-1-no.a-1][l];
					}
					else{
						pro=dp[ind3][l];
					}
					if(ind4==-1){
						pro=pro*dp2[n-1-no.a-1][m];
					}
					else{
						pro=pro*dp[ind4][m];
					}
					dp[ind2][i]=(dp[ind2][i]+pro)%mod;
				}
			}
		}
	}
	llo ans=0;
	for(llo i=0;i<6;i++){
		ans=(ans+dp[ind[1]][i])%mod;
	}
	cout<<ans<<endl;

 
 
 
	return 0;
}