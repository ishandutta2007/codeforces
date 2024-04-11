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
llo it[200001];
llo tree[5][400001];
void u(llo tt,llo i,llo j){
	while(i<=300000){
		tree[tt][i]+=j;
		i+=(i&-i);
	}
}
llo ss(llo tt,llo i){
	i=min(i,(llo)300000);
	llo su=0;
	while(i>0){
		su+=tree[tt][i];
		i-=(i&-i);
	}
	return su;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo ans=0;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		llo yy=it[i]*(ss(4,it[i]));
		yy-=(ss(3,it[i]));
		ans+=yy;
		for(llo j=0;j<=300000;j+=it[i]){
			llo xx=(ss(1,j+it[i]-1)-ss(1,j-1));
			xx-=((ss(2,j+it[i]-1)-ss(2,j-1))*j);
			ans+=xx;
			u(3,max(j,(llo)1),j);
			u(3,j+it[i],-j);
			u(4,max(j,(llo)1),1);
			u(4,j+it[i],-1);
		}
		cout<<ans<<" ";
		u(1,it[i],it[i]);
		u(2,it[i],1);

	}
	cout<<endl;
//	cout<<ans<<endl;



 
 

 
 
 
	return 0;
}