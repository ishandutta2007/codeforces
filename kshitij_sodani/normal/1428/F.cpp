
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

llo n;
llo it[500001];
llo pre[500001];
llo pre2[500001];
llo le[500001];
llo re[500001];
llo pre3[500001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		char s;
		cin>>s;
		if(s=='0'){
			it[i]=0;
		}
		else{
			it[i]=1;
		}
	}
	vector<pair<llo,llo>> pp;
	for(llo i=0;i<n;i++){
		pre[i]+=1;
		if(i>0){
			pre[i]+=pre[i-1];
		}
		if(it[i]==0){
			pre[i]=0;
		}
		if(it[i]==1){
			while(pp.size()){
				if(pp.back().a<=pre[i]){
					pp.pop_back();
				}
				else{
					break;
				}
			}
			if(pp.size()>0){
				le[i]=pp.back().b-pre[i]+1;
			}
			else{
				le[i]=0;
			}
			pp.pb({pre[i],i});
		}
	}
	pp.clear();
	for(llo i=n-1;i>=0;i--){
		pre2[i]+=1;

		pre2[i]+=pre2[i+1];
		
		if(it[i]==0){
			pre2[i]=0;
		}
		if(it[i]==1){
			while(pp.size()){
				if(pp.back().a<pre2[i]){
					pp.pop_back();
				}
				else{
					break;
				}
			}
			if(pp.size()>0){
				re[i]=pp.back().b+pre2[i]-2;
			}
			else{
				re[i]=n-1;
			}
			pp.pb({pre2[i],i});
		}
	}
	vector<pair<llo,llo>> ss;
	for(llo i=0;i<n;i++){
		if(it[i]==1){
			if(ss.size()==0){
				ss.pb({i,i});
			}
			else{
				if(i>ss.back().b+1){
					ss.pb({i,i});
				}
				else{
					ss[ss.size()-1].b+=1;
				}
			}
		}
	}
	for(llo i=1;i<=n;i++){
		pre3[i]=pre3[i-1]+(i*(i+1))/2;
	}

	llo ans=0;
	/*for(llo i=0;i<n;i++){
		cout<<le[i]<<".";
	}
	cout<<endl;
	for(llo i=0;i<n;i++){
		cout<<re[i]<<".";
	}
	cout<<endl;*/
	for(auto j:ss){

		/*cout<<j.a<<":"<<j.b<<endl;
		for(llo i=j.a;i<=j.b;i++){
			cout<<le[i]<<".";
		}
		cout<<endl;
		for(llo i=j.a;i<=j.b;i++){
			cout<<re[i]<<".";
		}
		cout<<endl;*/
		llo co=j.b-j.a+1;
		if(co>2){
			ans+=pre3[co-2];

		}
		for(llo i=j.a;i<j.b;i++){
			ans+=(i-j.a+1)*(j.a-le[i]+1);

		}
		for(llo i=j.a+1;i<=j.b;i++){
			ans+=(j.b-i+1)*(re[i]-j.b+1);
		}
		ans+=(j.b-j.a+1)*(j.a-le[j.b]+1)*(re[j.a]-j.b+1);
	}
	cout<<ans<<endl;



	return 0;
}