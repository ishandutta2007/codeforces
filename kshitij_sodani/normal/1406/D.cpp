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
llo it[100001];
llo vis[100001];
llo co[2];
llo st[100001];
llo tree[100001];
void u(llo i,llo j){
	while(i<=n){
		tree[i]+=j;
		i+=(i&-i);
	}
}
llo ss(llo i){
	llo su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}
void re(){
	//x ,it[0]-x+co[0];
	llo y=ss(1)+co[0];
//	cout<<ss(1)<<"<"<<co[0]<<endl;
	//cout<<y<<"::"<<endl;
	if(y<0){
		if((-y)%2==0){
			cout<<-((-y)/2)<<endl;
		}
		else{
			cout<<-((-y)/2)<<endl;
		}
		return;
	}
	cout<<(y+1)/2<<endl;



}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	for(llo i=0;i<n;i++){
		if(i==0){
			u(i+1,it[i]);
		}
		else{
			u(i+1,it[i]-it[i-1]);
		}
	}
	for(llo i=0;i<n-1;i++){
		if(it[i]<it[i+1]){
			co[0]+=it[i+1]-it[i];
			st[i]=0;
		}
		else{
			co[1]+=it[i]-it[i+1];
			st[i]=1;
		}
	}

	llo q;
	cin>>q;
//	cout<<co[0]<<":"<<co[1]<<endl;
	re();

	while(q--){
		llo l,r,x;
		cin>>l>>r>>x;
		l--;
		r--;
		if(l>0){
			co[st[l-1]]-=abs(ss(l+1)-ss(l));
		}
		if(r<n-1){
			co[st[r]]-=abs(ss(r+2)-ss(r+1));
		}

		u(l+1,x);
		u(r+2,-x);
		/*for(llo i=1;i<=n;i++){
			cout<<ss(i)<<":";
		}
		cout<<endl;*/
		if(l>0){
			llo xx=ss(l);
			llo yy=ss(l+1);
			if(xx<yy){
				st[l-1]=0;
				co[0]+=yy-xx;
			}
			else{
				st[l-1]=1;
				co[1]+=xx-yy;
			}
		}
		if(r+1<n){
			llo xx=ss(r+1);
			llo yy=ss(r+2);
			if(xx<yy){
				st[r]=0;
				co[0]+=yy-xx;
			}
			else{
				st[r]=1;
				co[1]+=xx-yy;
			}
		}
		//cout<<co[0]<<":"<<co[1]<<endl;
		re();
	}










 
	return 0;
}