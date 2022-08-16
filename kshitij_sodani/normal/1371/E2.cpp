#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

llo n,p;
llo it[100001];
llo co[100001];
llo vis[100001];
llo ans[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>p;
	llo ma=0;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		ma=max(ma,it[i]-(n-1));
	}

	for(llo i=0;i<n;i++){
		it[i]-=ma;
	//	cout<<it[i]<<endl;
		co[max(it[i],(llo)0)]+=1;
	}
	for(llo i=1;i<n;i++){
		co[i]+=co[i-1];
	}
/*	for(llo i=0;i<n;i++){
		cout<<co[i]<<";";
	}
	cout<<endl;*/
	llo ind=n;
	for(llo i=n-1;i>=0;i--){
		llo y=p-((co[i]-i)%p);
		y%=p;
		if(vis[y]==0){
			vis[y]=1;
			llo ii=i-y;

			for(llo j=y;ii>=0;j+=p,ii-=p){
				ans[j]=1;
			//	cout<<i<<";"<<ii<<";"<<j<<endl;
			}
		}
		if(i==n-1){
			for(llo j=y;j<=n;j++){
				ans[j]=1;
			}
		}
	}
	llo co=0;
	for(llo i=0;i<n;i++){
		if(ans[i]==0){
			co+=1;
		}
	}
	cout<<co<<endl;
	for(llo i=0;i<n;i++){
		if(ans[i]==0){
			cout<<ma+i<<" ";
		}
	}
	cout<<endl;
/*	vector<llo> ans;

	for(llo i=0;i<=2001;i++){
		for(llo j=0;j<n;j++){
			co[j]=0;
		}
		llo kk=0;
		for(llo j=0;j<n;j++){
			llo y=it[j]-i;
			if(y>=n){
				kk=1;
				break;
			}
			co[max(y,0)]+=1;
			
		}
		if(kk==1){
			continue;
		}
		llo cur=0;
		llo st=0;
		for(llo j=0;j<n;j++){
			cur+=co[j];
			llo ac=(cur-j);
		//	cout<<ac<<endl;
			if(ac<0){
				st=1;
				break;
			}
			if(ac%p==0){
				st=1;
			}
		}
		if(st==0){
			ans.pb(i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto j:ans){
		cout<<j<<" ";
	}
	cout<<endl;
*/




	return 0;
}