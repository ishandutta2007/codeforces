#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
llo n,x;
llo aa[400001];
llo pre[400001];
llo pre2[400001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>x;
	llo sa=0;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
		sa=max(sa,aa[i]);
	}
	if(x==1){
		cout<<sa<<endl;
		return 0;
	}
	for(llo i=n;i<2*n;i++){
		aa[i]=aa[i-n];
	}
	pre[0]=(aa[0]*(aa[0]+1))/2;
	for(llo i=1;i<2*n;i++){
		pre[i]=pre[i-1];
		pre[i]+=(aa[i]*(aa[i]+1))/2;
	}
	pre2[0]=aa[0];
	for(llo i=1;i<2*n;i++){
		pre2[i]=pre2[i-1];
		pre2[i]+=aa[i];
	}
	llo pp=1;
	llo ma=0;
	for(llo i=0;i<n;i++){
	//	cout<<i<<endl;
		pp=max(pp,i+1);
		llo cur=0;
		if(i>0){
			cur=pre2[i-1];
		}
		while(true){
			if(pre2[pp]-cur<=x){
				pp+=1;
			}
			else{
				break;
			}
		}
		llo st=1;
		if(aa[i]>=x){
			ma=max(ma,((aa[i]-x+1+aa[i])*x)/(llo)2);
			continue;
		}

		llo indd=max(x-(pre2[pp-1]-cur),(llo)0);
	//	cout<<pp<<endl;
	//	cout<<st<<","<<indd<<endl;
		//if(st<indd){
		if(indd>0){
			llo y=min(aa[i]-st,aa[pp]-indd);
	//		cout<<i<<":"<<aa[i]<<":"<<aa[pp]<<endl;
			st+=y;
			indd+=y;
		}
		//}
	//		cout<<st<<","<<indd<<endl;
		llo ans=pre[pp-1]-pre[i];
		ans+=((aa[i]+st)*(aa[i]-st+1))/2;
		ans+=(indd*(indd+1))/2;
		ma=max(ma,ans);

	}
	cout<<ma<<endl;




	


	return 0;
}