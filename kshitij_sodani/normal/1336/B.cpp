#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
#define pb push_back
typedef long long  llo;
llo mod=1000000007;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m,c;
		cin>>n>>m>>c;
	
		llo x;
		set<llo> aa;
		set<llo> bb;
		set<llo> cc;
		for(llo i=0;i<n;i++){

			cin>>x;
			aa.insert(x);
		}
		for(llo i=0;i<m;i++){
			cin>>x;
			bb.insert(x);
		}
		for(llo i=0;i<c;i++){
			cin>>x;
			cc.insert(x);
		}
		llo mi=-1;

		for(auto nn:aa){
			auto xx=bb.upper_bound(nn);
			auto yy=cc.lower_bound(nn);
			if(xx==bb.begin()){
				continue;
			}
			if(yy==cc.end()){
				continue;
			}
			xx--;
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);

			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);

			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}
		for(auto nn:aa){
			auto xx=bb.lower_bound(nn);
			auto yy=cc.upper_bound(nn);
			if(yy==cc.begin()){
				continue;
			}
			if(xx==bb.end()){
				continue;
			}
			yy--;
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}
		for(auto nn:bb){
			auto xx=aa.upper_bound(nn);
			auto yy=cc.lower_bound(nn);

			if(xx==aa.begin()){
				continue;
			}
			if(yy==cc.end()){
				continue;
			}

			xx--;
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}
		for(auto nn:bb){
			auto xx=aa.lower_bound(nn);
			auto yy=cc.upper_bound(nn);
			if(yy==cc.begin()){
				continue;
			}
			if(xx==aa.end()){
				continue;
			}
			yy--;
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}

		for(auto nn:cc){
			auto xx=aa.upper_bound(nn);
			auto yy=bb.lower_bound(nn);
			if(xx==aa.begin()){
				continue;
			}
			if(yy==bb.end()){
				continue;
			}
			xx--;
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}
		for(auto nn:cc){
			auto xx=aa.lower_bound(nn);
			auto yy=bb.upper_bound(nn);
			if(yy==bb.begin()){
				continue;
			}
			if(xx==aa.end()){
				continue;
			}
			yy--;
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
		//	cout<<ac<<" "<<bc<<" "<<nn<<endl;

			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}






/*


for(auto nn:aa){
			auto xx=bb.lower_bound(nn);
			auto yy=cc.lower_bound(nn);
			if(xx==bb.end()){
				continue;
			}
			if(yy==cc.end()){
				continue;
			}
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);

			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);

			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}
		for(auto nn:aa){
			auto xx=bb.lower_bound(nn);
			auto yy=cc.lower_bound(nn);
			if(yy==cc.end()){
				continue;
			}
			if(xx==bb.end()){
				continue;
			}
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}
		for(auto nn:bb){
			auto xx=aa.lower_bound(nn);
			auto yy=cc.lower_bound(nn);

			if(xx==aa.end()){
				continue;
			}
			if(yy==cc.end()){
				continue;
			}

			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}
		for(auto nn:bb){
			auto xx=aa.lower_bound(nn);
			auto yy=cc.lower_bound(nn);
			if(yy==cc.end()){
				continue;
			}
			if(xx==aa.end()){
				continue;
			}
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}

		for(auto nn:cc){
			auto xx=aa.lower_bound(nn);
			auto yy=bb.lower_bound(nn);
			if(xx==aa.end()){
				continue;
			}
			if(yy==bb.end()){
				continue;
			}
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}
		for(auto nn:cc){
			auto xx=aa.lower_bound(nn);
			auto yy=bb.lower_bound(nn);
			if(yy==bb.end()){
				continue;
			}
			if(xx==aa.end()){
				continue;
			}
			llo ac=*xx;
			llo bc=*yy;
			llo co=(ac-bc)*(ac-bc);
			co+=(ac-nn)*(ac-nn);
			co+=(nn-bc)*(nn-bc);
		//	cout<<ac<<" "<<bc<<" "<<nn<<endl;

			if(mi==-1){
				mi=co;
			}
			else{
				mi=min(mi,co);
			}
		}
		
	}

*/
		cout<<mi<<endl;
	}



















	return 0;
}