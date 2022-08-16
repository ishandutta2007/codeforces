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
llo aa[2501];
llo bb[2501];
pair<llo,llo> cur;
llo area(pair<llo,llo> ac,pair<llo,llo> bc,pair<llo,llo> cd){
	return abs(ac.a*(bc.b-cd.b)+bc.a*(cd.b-ac.b)+cd.a*(ac.b-bc.b));	
}
bool clock(pair<llo,llo> ac,pair<llo,llo> bc,pair<llo,llo> cd){
	return ac.a*(bc.b-cd.b)+bc.a*(cd.b-ac.b)+cd.a*(ac.b-bc.b)<0;
}
bool cmp2(pair<llo,llo> x,pair<llo,llo> y){
	return (x.b-cur.b)*(y.a-x.a)-(x.a-cur.a)*(y.b-x.b)<0;
}
llo quad(pair<llo,llo> x){
	if(x.a<0 and x.b>=0){
		return 1;
	}
	else if(x.a>=0 and x.b>=0){
		return 0;
	}
	else if(x.a<0 and x.b<0){
		return 2;
	}
	else{
		return 3;
	}
}
bool cmp(pair<llo,llo> x,pair<llo,llo> y){
	llo ac=quad({x.a-cur.a,x.b-cur.b});
	llo bc=quad({y.a-cur.a,y.b-cur.b});
	if(ac==bc){
		return cmp2(x,y);
	}
	else{
		return ac<bc;
	}
	/*if(y.a<x.a){

		if(x.a<cur.a){
			return (x.b-cur.b)*(y.a-x.a)-(x.a-cur.a)*(y.b-x.b)>=0;	
		}
		else{
			return (x.b-cur.b)*(y.a-x.a)-(x.a-cur.a)*(y.b-x.b)<0;
		}
	}
	else{
		if(x.a<cur.a){
			return (x.b-cur.b)*(y.a-x.a)-(x.a-cur.a)*(y.b-x.b)<0;
		}
		else{
			return (x.b-cur.b)*(y.a-x.a)-(x.a-cur.a)*(y.b-x.b)>=0;
		}
	}
	*/
}
llo nee[5001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>aa[i]>>bb[i];
	}
	for(int i=0;i<=2*n;i++){
		nee[i]=i%(n-1);
	}
	llo cot=0;
	for(llo i=0;i<n;i++){
		vector<pair<llo,llo>> ss;
		for(llo j=0;j<n;j++){
			if(i!=j){
				ss.pb({aa[j],bb[j]});
			}
		}
		cur={aa[i],bb[i]};
		sort(ss.begin(),ss.end(),cmp);
		//llo ind=0;
		llo xx=-1;
		int st=1;
		/*for(int j=0;j<ss.size()-1;j++){
			if(clock(cur,ss[j],ss[j+1])){
				cout<<j<<":"<<endl;
			}
		}*/
		for(auto j:ss){
			xx+=1;
			/*if(ind!=xx){
				if(clock({aa[i],bb[i]},j,ss[ind])==false){
					ind=xx;
				}
			}*/
			llo low=0;
			llo high=n-2;
			while(low<high-1){
				llo mid=(low+high)/2;
				if(mid==0){
					low=mid;
					continue;
				}
				llo ne=(xx+mid);
				if(!clock({aa[i],bb[i]},j,ss[nee[(xx+mid)]])){
					low=mid;
				}
				else{
					high=mid;
				}
			}
			llo co=low;
			if(high>0){
				if(!clock({aa[i],bb[i]},j,ss[nee[(xx+high)]])){
					co=max(co,high);
				}
			}
			/*while(ind+1<xx){
				llo ne=ind+1;
				if(ne>=n-1){
					ne-=(n-1);
				}
				if(clock({aa[i],bb[i]},j,ss[ne])){
					ind=ne;
				}
				else{
					break;
				}
			}		
			llo co=0;
			if(ind>=xx){
				co=ind-xx;
			}	
			else{
				co=(n-2)-xx+ind+1;
			}*/
			cot+=((co*(co-1))/2);
		}

/*		for(auto j:ss){
			cout<<j.a<<":"<<j.b<<endl;

		}
		cout<<endl;*/
	//	cout<<cot<<endl;
		/*for(llo j=0;j<n;j++){
			if(i==j){
				continue;
			}
			llo co=0;
			for(llo k=0;k<n;k++){
				if(k==i or k==j){
					continue;
				}
				if(clock({aa[i],bb[i]},{aa[j],bb[j]},{aa[k],bb[k]})){
					co+=1;
				}
			}*/
		//	cot+=((co*(co-1))/2);
		//	cout<<i<<":"<<j<<":"<<co<<endl;
		/*	for(llo k=j+1;k<n;k++){
				for(llo l=k+1;l<n;l++){
					if(i==j or i==k or i==l){
						continue;
					}
					llo cur=area({aa[i],bb[i]},{aa[j],bb[j]},{aa[k],bb[k]})+area({aa[i],bb[i]},{aa[j],bb[j]},{aa[l],bb[l]});
					cur+=area({aa[i],bb[i]},{aa[k],bb[k]},{aa[l],bb[l]});
					if(cur==area({aa[j],bb[j]},{aa[k],bb[k]},{aa[l],bb[l]})){
						cot+=(n-4);
					}
				}
			}*/
		//}
	}
	//cout<<((n*(n-1)*(n-2)*(n-3))/24)*4<<":"<<cot<<endl;
	cot=((n*(n-1)*(n-2)*(n-3))/24)*4-cot;
	cot*=(n-4);
	cot/=2;
	cout<<cot<<endl;
	return 0;

/*
	for(llo i=0;i<n;i++){
		vector<pair<llo,llo>> ss;
		for(llo j=0;j<n;j++){
			if(i!=j){
				ss.pb({aa[j],bb[j]});
			}
		}
		cur={aa[i],bb[i]};
		sort(ss.begin(),ss.end(),cmp);
		for(auto j:ss){
			llo aa=0;
			llo bb=0;
			for(auto jj:ss){
				if(j.a!=jj.a or j.b!=jj.b){
					if(clock(cur,j,jj)){
						aa+=1;
					}
					else{
						bb+=1;
					}
				}
			}
			if(aa>0){
				cot+=((aa*(aa-1))/2)*bb;

			}
			if(bb>0){
				cot+=((bb*(bb-1))/2)*aa;
			}
			cout<<j.a<<","<<j.b<<","<<aa<<":"<<bb<<endl;
		}
		cout<<endl;

	}
	cout<<cot<<endl;
	llo ans=(n*(n-1)*(n-2)*(n-3)*(n-4));

	ans/=120;
	ans*=5;
	cout<<ans<<endl;
	ans-=(cot/2);
	cout<<ans<<endl;

*/



 
	return 0;
}