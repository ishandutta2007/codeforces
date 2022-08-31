//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//
int n,k;
int add(int i){
	cout<<"? "<<i+1<<endl;
	//return 0;
	string s;
	cin>>s;
	if(s=="Y"){
		return 1;
	}
	else{
		return 0;
	}
}
void erase(){
	cout<<"R"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans=0;
	cin>>n>>k;
	set<int> cur;
	for(int i=0;i<n;i++){
		cur.insert(i);
	}
	int ind=0;
	vector<vector<int>> rr;
	vector<int> xx;
	int cot=0;
	while(ind<n){
		int zz=add(ind);
		cot++;
		if(zz==1){
			cur.erase(ind);
		}
		else{
			xx.pb(ind);
		}
		if(cot==k){
			rr.pb(xx);
			erase();
			cot=0;
			xx.clear();
		}
		ind++;
	}
	if(xx.size()){
		rr.pb(xx);
	}

	for(int i=0;i<rr.size();i++){
		int xx=i;
		erase();
		for(int j=0;j<rr.size();j++){
			for(auto kk:rr[xx]){
				if(cur.find(kk)==cur.end()){
					continue;
				}
				int z=add(kk);
				if(z==1){
					cur.erase(kk);
				}

			}
			//cout<<xx<<":"<<endl;;
			if(j%2==0){
				xx=(xx-(j+1)+rr.size())%(rr.size());
			}
			else{
				xx=(xx+(j+1)+rr.size())%rr.size();
			}
		}

	/*	for(int j=i+1;j<rr.size();j++){
			for(auto kk:rr[i]){
				add(kk);
			}
			for(auto kk:rr[j]){
				int z=add(kk);
				if(z==1){
					cur.erase(kk);
					//cout<<kk<<":"<<endl;
				}
			}
			erase();
			reverse(rr[i].begin(),rr[i].end());
			reverse(rr[j].begin(),rr[j].end());
			for(auto kk:rr[i]){
				add(kk);
			}
			for(auto kk:rr[j]){
				int z=add(kk);
				if(z==1){
					cur.erase(kk);
					//cout<<kk<<":"<<endl;
				}
			}
			erase();
			reverse(rr[i].begin(),rr[i].end());
			reverse(rr[j].begin(),rr[j].end());

		}*/
	}
	cout<<"! "<<cur.size()<<endl;
	









	return 0;
}