//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,m;
llo aa[200001];
llo ans[200001];
llo bb[200001];
pair<llo,llo> yy[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;

	for(llo i=0;i<n;i++){
		cin>>aa[i]>>bb[i];
		
	}
	vector<pair<pair<llo,llo>,llo>> ss;
	for(llo i=0;i<n-1;i++){
		pair<llo,llo> xx={aa[i+1]-bb[i],bb[i+1]-aa[i]};
		yy[i]=xx;
		ss.pb({{xx.a,-1},i});
		ss.pb({{xx.b,1},i});
	}
	for(llo i=0;i<m;i++){
		llo cc;
		cin>>cc;
		ss.pb({{cc,0},i});
	}
	sort(ss.begin(),ss.end());
	priority_queue<pair<llo,llo>> qq;
	llo co=0;
	for(auto j:ss){
		if(j.a.b==-1){
			qq.push({-yy[j.b].b,j.b});
		}
		else if(j.a.b==1){

		}
		else{
			while(qq.size()){
				if((-qq.top().a)<j.a.a){
					qq.pop();

				}
				else{
					break;
				}
			}
			if(qq.size()){
				ans[qq.top().b]=j.b;
				co++;
				qq.pop();
			}
		}
	}
	if(co==n-1){
		cout<<"Yes"<<endl;
		for(llo i=0;i<n-1;i++){
			cout<<ans[i]+1<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"No"<<endl;
	}

	



 
	return 0;
}