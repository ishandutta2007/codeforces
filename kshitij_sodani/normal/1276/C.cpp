//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n;


llo pre[500001];
llo co[500001];
vector<llo> ans[5000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<llo,llo> ss;
	cin>>n;
	for(llo i=0;i<n;i++){
		llo aa;
		cin>>aa;
		ss[aa]++;
	}
	for(auto j:ss){
		co[j.b]++;
	}
	pair<llo,pair<llo,llo>> ma={0,{0,0}};
	for(llo i=1;i<=n;i++){
		pre[i]=pre[i-1]+co[i]*i;
		co[i]+=co[i-1];
		llo cur=(((llo)ss.size()-co[i])*i+pre[i])/i;
		//cout<<pre[i]<<","<<cur<<endl;
		if(cur>=i){
			ma=max(ma,{cur*i,{i,cur}});
		}

	}
	//cout<<endl;
	//cout<<ma.a<<":"<<ma.b.a<<":"<<ma.b.b<<endl;
	cout<<ma.a<<endl;

	swap(ma.b.a,ma.b.b);
	cout<<ma.b.a<<" "<<ma.b.b<<endl;
	for(llo i=0;i<ma.b.a;i++){
		for(llo j=0;j<ma.b.b;j++){
			ans[i].pb(-1);
		}
	}
	if(ma.b.a==ma.b.b){
		vector<pair<llo,llo>> tt;
		
		for(auto j:ss){
			for(llo i=0;i<min(ma.b.a,j.b);i++){
				tt.pb({min(ma.b.a,j.b),j.a});
			}
		}
		sort(tt.begin(),tt.end());
		reverse(tt.begin(),tt.end());
		pair<llo,llo> cur={0,0};
	//	return 0;
		//
		for(llo i=0;i<ma.b.a*ma.b.b;i++){

			ans[(cur.a+cur.b)%ma.b.b][cur.b]=tt[i].b;
			if(cur.b==ma.b.b-1){
				cur.a=(cur.a+1)%ma.b.a;
				cur.b=0;
			}
			else{
				cur.b=(cur.b+1)%(ma.b.b);
			}

			/*if(i%ma.b.a==ma.b.a-1){
				cur.b=(cur.b+1)%ma.b.a;
			}
			else{
				cur.a=(cur.a+1)%ma.b.a;
				cur.b=(cur.b+1)%ma.b.a;
			}*/
		}
		for(llo i=0;i<ma.b.a;i++){
			for(llo j=0;j<ma.b.a;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}

	}
	else{
		vector<llo> tt;
		
		for(auto j:ss){
			for(llo i=0;i<min(ma.b.b,j.b);i++){
				tt.pb(j.a);
			}
		}
		sort(tt.begin(),tt.end());
		pair<llo,llo> cur={0,0};
		for(llo i=0;i<ma.b.a*ma.b.b;i++){
			ans[(cur.a-cur.b+ma.b.a)%ma.b.a][cur.b]=tt[i];
			if(cur.b==ma.b.b-1){
				cur.a=(cur.a+1)%ma.b.a;
				cur.b=0;
			}
			else{
				cur.b=(cur.b+1)%(ma.b.b);
			}
		}
		for(llo i=0;i<ma.b.a;i++){
			for(llo j=0;j<ma.b.b;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}

	}







 
	return 0;
}