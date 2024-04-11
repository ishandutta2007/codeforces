#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n;
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	sort(it,it+n);
	llo pre[20];
	for(llo i=0;i<20;i++){
		pre[i]=0;
	}
	for(llo i=0;i<n;i++){
	/*	for(llo j=0;j<20;j++){
			llo x=it[i]&it[i-1];
			it[i]=it[i]|it[i-1];
			it[i-1]=x;
		}*/
		for(llo j=0;j<20;j++){
			if(it[i]&(1<<j)){
				pre[j]+=1;
			}
		}
	}
	llo co=0;
	for(llo i=0;i<n;i++){
		llo kk=0;
		for(llo j=0;j<20;j++){
			if(pre[j]>0){
				kk+=(1<<j);
				pre[j]--;
			}
		}
		co+=(kk*kk);
	}
	cout<<co<<endl;



	return 0;
}