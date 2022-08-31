//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,q;
string s;
string t;
llo mod=1e9+7;
llo pre[100010];
llo pre3[100010];
llo pre2[26][100010];

llo ans=0;
llo cot=0;
void solve(vector<llo> tt,llo ind=0){

	if(ind>cot){
		return;
	}
	if(tt.size()==1){
		/*if(cot==2){
			cout<<pre[ind]<<":"<<(pre2[tt[0]][cot]-pre2[tt[0]][ind-1]+mod)<<endl;
		}*/
		ans=(ans+pre[cot]*(pre2[tt[0]][cot]-pre2[tt[0]][ind-1]+mod))%mod;
		return;
	}
	/*cout<<ind<<"::";
	for(auto j:tt){
		cout<<j<<"<<";
	}
	cout<<endl;*/
	//for(llo i=0;i<2;i++){
		vector<llo> gg;
		vector<llo> hh;
		llo st1=1;
		llo st2=1;
		for(llo j=0;j<tt.size();j+=2){
			gg.pb(tt[j]);
			if(tt[j]!=(t[ind-1]-'a')){
				st1=0;
			}
		}
		for(llo j=1;j<tt.size();j+=2){
			hh.pb(tt[j]);
			if(tt[j]!=(t[ind-1]-'a')){
				st2=0;
			}
		}
		if(st1){
			if(hh.size()==0){
				ans=(ans+pre[cot-ind]);
				//cout<<cot<<",,"<<ind<<endl;
				if(ans>=mod){
					ans-=mod;
				}
			}
			else{
				solve(hh,ind+1);
			}
		}
		if(st2){
			if(gg.size()==0){
				ans=(ans+pre[cot-ind]);
				if(ans>=mod){
					ans-=mod;
				}
			}
			else{
				solve(gg,ind+1);
			}
		}




	//}


}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	cin>>s;
	cin>>t;
	pre[0]=1;
	pre3[0]=1;
	for(llo i=1;i<=100005;i++){
		pre[i]=(pre[i-1]*2)%mod;
		pre3[i]=(pre3[i-1]*((mod+1)/2))%mod;
	}
	for(llo i=0;i<26;i++){
		for(llo j=1;j<=t.size();j++){
			pre2[i][j]=pre2[i][j-1];
			if(t[j-1]-'a'==i){
				pre2[i][j]+=pre3[j];
				if(pre2[i][j]>=mod){
					pre2[i][j]-=mod;
				}
			}
		}
	}
	llo ee=s.size();
	for(llo ii=0;ii<q;ii++){
		llo aa;
		string ss;
		cin>>aa>>ss;
		ans=0;
		cot=aa;
		/*if(ss.size()==1){

		}*/

		for(llo i=-1;i<(llo)s.size();i++){
			vector<llo> tt;
			llo ind=i;
			llo st=1;
		//	cout<<ii<<":"<<i<<endl;
			for(llo j=0;j<ss.size();j++){
				if(ind==-1){
					ind=0;
					tt.pb(ss[j]-'a');
					continue;
				}
				else{
					if(ss[j]!=s[ind]){
						/*if(ii==0 and i==1){
							cout<<j<<":"<<ind<<endl;
						}*/
						st=0;
					}
					if(ind==s.size()-1){
						ind=-1;
					}
					else{
						ind++;
					}
				}
			}
			if(st==0){
				continue;
			}
		/*	cout<<ii<<":"<<i<<endl;
			for(auto j:tt){
				cout<<j<<",";
			}
			cout<<endl;*/
			if(tt.size()==0){
				ans+=pre[aa];
				if(ans>=mod){
					ans-=mod;
				}
				continue;
			}
			solve(tt,1);
		}
		cout<<ans<<endl;
		/*for(llo j=0;j<=s.size();j++){
			if(j+1>ss.size()){
				continue;
			}
			llo st=1;
			vector<llo> tt;
			llo ind=s.size()-1;
			for(llo i=j-1;i>=0;i--){
				if(ss[i]!=s[ind]){
					st=0;
					break;
				}
				ind--;
			}
			if(st==0){
				continue;
			}
			vector<llo> tt;
			for(llo i=)

		}*/
	}




 
	return 0;
}