
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int aa[2001];
int bb[2001];
int cc[2001];
int dd[2001];
int pre[2001*2001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>aa[i]>>bb[i];
	}

	for(int i=0;i<m;i++){
		cin>>cc[i]>>dd[i];
	}

	vector<pair<int,int>> kk;
	for(int i=0;i<n;i++){
		int ma=0;
		int mi=0;
		for(int j=0;j<m;j++){
			//cout<<i<<":"<<j<<endl;
			if(aa[i]>cc[j]){
				continue;
			}
			if(bb[i]>dd[j]){
				continue;
			}
			kk.pb({cc[j]-aa[i]+1,dd[j]-bb[i]+1});
		//	cout<<cc[j]-aa[i]+1<<endl;
		/*	ma=max(ma,cc[j]-aa[i]+1);
			mi=max(mi,dd[j]-bb[i]+1);*/
		}
		
		//cout<<ma<<":"<<mi<<endl;
	}
	if(kk.size()==0){
		cout<<0<<endl;
		return 0;
	}
	sort(kk.begin(),kk.end());

	int ans=0;
	for(auto j:kk){
		ans=max(ans,j.a);
	}
	int ans2=0;
	for(auto j:kk){
		ans2=max(ans2,j.b);
	}
	ans=min(ans,ans2);
	for(int i=(int)(kk.size())-1;i>=0;i--){
		pre[i]=max(pre[i+1],kk[i].b);
	}
	//cout<<ans<<endl;
	/*for(auto j:kk){
		cout<<j.a<<","<<j.b<<endl;
	}*/
	for(int i=(int)(kk.size())-2;i>=0;i--){
		if(kk[i].a<kk[i+1].a){
			ans=min(ans,kk[i].a+pre[i+1]);
		}
/*
		ee=max(ee,kk[i].b);*/
	}
	cout<<ans<<endl;




/*	int low=0;
	int high=1e6+1;
	while(low<high-1){
		int mid=(low+high)/2;
		if(check(mid)){
			high=mid;
		}
		else{
			low=mid;
		}
	}
	int ans=high;
	if(check(low)){
		ans=min(ans,low);
	}

*/






	return 0;
}