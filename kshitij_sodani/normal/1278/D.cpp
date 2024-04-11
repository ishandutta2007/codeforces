#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define a first
#define b second
#define mp make_pair
typedef long long int llo;
 
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
llo par[500001];
llo find(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo aa,bb;
	llo n;
	cin>>n;
	vector<pair<llo,llo>> it;
	llo tt[n][2];
	for(llo i=0;i<n;i++){
		cin>>aa>>bb;
		it.pb(mp(aa,i));
		it.pb(mp(bb,i));
		tt[i][0]=aa;
		tt[i][1]=bb;
	}
	sort(it.begin(),it.end());
	//llo vis[n];
	//memset(vis,0,sizeof(vis));
	set<pair<llo,llo>> vis;
	for(llo i=0;i<n;i++){
		par[i]=i;
	}
	llo cnt=0;
	llo st=1;
	llo x,y;
	for(llo i=0;i<2*n;i++){
		if(cnt>=n or st==0){
			break;
		}
		if(vis.count(mp(it[i].a,it[i].b))){
			vis.erase(mp(it[i].a,it[i].b));//y_value,index
			continue;
		}
		else{
			for(auto j:vis){
		//		cout<<j.b<<" ";
				if(j.a>tt[it[i].b][1]){
					break;
				}
				x=find(j.b);
				y=find(it[i].b);
				if(x==y){
					st=0;
					break;
				}
				par[y]=x;
				cnt++;
				if(cnt>=n){
					break;
				}
		
			}
		//	cout<<endl;
			vis.insert(mp(tt[it[i].b][1],it[i].b));
		}
	}
	//cout<<st<<" "<<cnt<<endl;
	if(st==0 or cnt!=n-1){
		cout<<"NO";
	}
	else{
		cout<<"YES";
	}














	return 0;
}