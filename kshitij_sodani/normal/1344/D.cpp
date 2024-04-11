
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

llo n,k;
llo it[100001];
llo tt[100001];
llo check(llo mid){
	llo su=0;
	for(llo i=0;i<n;i++){
		llo low=0;
		llo high=it[i]-1;
		if(it[i]-1<mid){
			tt[i]=0;
			continue;
		}
		while(low<high-1){
			llo mi=(low+high)/2;
			if(it[i]-(mi*mi*3+mi*3+1)>=mid){
				low=mi;
			}
			else{
				high=mi;
			}
		}
		tt[i]=low;
		llo mi=high;
		if(it[i]-(mi*mi*3+mi*3+1)>=mid){
			tt[i]=max(tt[i],high);
		}
		tt[i]+=1;
		su+=tt[i];
	}
	return su;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	llo low=-4e18;
	llo high=1e9;
	while(low<high-1){
		llo mid=(low+high)/2;
		if(check(mid)<=k){
			high=mid;
		}
		else{
			low=mid;
		}
	}

	llo ind=high;
	if(check(low)<=k){
		ind=max(ind,low);
	}
/*	cout<<ind<<":"<<check(ind)<<endl;
	for(int i=0;i<n;i++){
		cout<<tt[i]<<":";
	}
	cout<<endl;*/
	llo le=k-check(ind);
	for(llo i=0;i<n;i++){
		if(it[i]-(tt[i]*tt[i]*3+tt[i]*3+1)==ind-1){
			if(le>0){
				tt[i]+=1;
				le-=1;
			}
		}
	}
	for(llo i=0;i<n;i++){
		cout<<tt[i]<<" ";
	}
	cout<<endl;














	return 0;
}