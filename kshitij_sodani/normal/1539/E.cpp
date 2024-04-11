#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;

llo n,m;
llo it[100001];
llo aa[100001];
llo bb[100001];
llo cc[100001];
llo dd[100001];
pair<llo,llo> ba[100001][2];
llo ans[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	set<pair<llo,llo>> ss;
	set<pair<llo,llo>> tt;


	ss.insert({0,-1});
	tt.insert({0,-1});
	for(llo i=0;i<n;i++){
		cin>>it[i];
		cin>>aa[i]>>bb[i];
		cin>>cc[i]>>dd[i];
		ba[i][0]={-1,-1};
		ba[i][1]={-1,-1};
		if(it[i]>=aa[i] and it[i]<=bb[i] and it[i]>=cc[i] and it[i]<=dd[i]){
			while(tt.size()){
				if((*tt.begin()).a<cc[i]){
					tt.erase(tt.begin());
				}
				else{
					break;
				}
			}
			while(tt.size()){
				auto j=tt.end();
				j--;
				if((*j).a>dd[i]){
					tt.erase(j);
				}
				else{
					break;
				}
			}


			while(ss.size()){
				if((*ss.begin()).a<aa[i]){
					ss.erase(ss.begin());
				}
				else{
					break;
				}
			}
			while(ss.size()){
				auto j=ss.end();
				j--;
				if((*j).a>bb[i]){
					ss.erase(j);
				}
				else{
					break;
				}
			}
			llo xx=ss.size();
			llo yy=tt.size();
			if(xx){
				ba[i][1]=*(ss.begin());
			}
			if(yy){
				ba[i][0]=*(tt.begin());
			}
			if(yy){
				ss.insert({it[i],i});
			}
			if(xx){
				tt.insert({it[i],i});
			}


			continue;
		}
		if(it[i]>=aa[i] and it[i]<=bb[i]){
			while(tt.size()){
				if((*tt.begin()).a<cc[i]){
					tt.erase(tt.begin());
				}
				else{
					break;
				}
			}
			while(tt.size()){
				auto j=tt.end();
				j--;
				if((*j).a>dd[i]){
					tt.erase(j);
				}
				else{
					break;
				}
			}
			if(tt.size()){
				ba[i][0]=*(tt.begin());
			//	ss.insert({it[i],i});
			}
		}
		else{
			tt.clear();
		}

		if(it[i]>=cc[i] and it[i]<=dd[i]){
			while(ss.size()){
				if((*ss.begin()).a<aa[i]){
					ss.erase(ss.begin());
				}
				else{
					break;
				}
			}
			while(ss.size()){
				auto j=ss.end();
				j--;
				if((*j).a>bb[i]){
					ss.erase(j);
				}
				else{
					break;
				}
			}
			if(ss.size()){
				ba[i][1]=*(ss.begin());
				tt.insert({it[i],i});
			}
		}
		else{
			ss.clear();
		}
		if(ba[i][0].a>=0){
			ss.insert({it[i],i});
		}
	}
	llo st=-1;
	for(llo i=0;i<2;i++){
		if(ba[n-1][i].a>=0){
			st=i;
		}
	}
	if(st==-1){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	vector<pair<llo,llo>> xx;
	llo cur=n-1;
	while(cur>=0){
		for(llo i=cur;i>ba[cur][st].b;i--){
			ans[i]=st;
		}
		cur=ba[cur][st].b;
		st^=1;



	}



	for(llo i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;








	return 0;
}