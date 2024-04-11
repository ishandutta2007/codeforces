
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		sort(it,it+n);
		llo su=0;
		for(llo i=0;i<n;i++){
			if(i==0){
				su+=(n-1)*it[i];
			}
			else{
				su+=it[i];
			}
		}
		if(su>0){
			cout<<"INF"<<endl;
			continue;
		}
		su=0;
		for(llo i=0;i<n;i++){
			if(i==n-1){
				su+=(n-1)*it[i];
			}
			else{
				su+=it[i];
			}
		}
		if(su<0){
			cout<<"INF"<<endl;
			continue;
		}
		llo ans=-(llo)1e18;
		 su=0;
		for(llo i=1;i<n-1;i++){
			su+=it[i];
		}
		llo su2=0;
		for(llo i=0;i<n-1;i++){
			pair<llo,llo> cc={-it[i+1],-it[i]};
			if(i>0){
				su2+=it[i];
				su-=it[i];
			}
			llo cur=0;
			cur+=it[0]*it[n-1];
			cur+=su2*it[n-1];
			cur+=su*it[0];
			//i right
			//1 common
			llo cur2=(i+1)*it[n-1];
			cur2+=(n-2-i+1)*it[0];
			cur2+=su+su2;
			ans=max(ans,cur+cur2*cc.a);
			ans=max(ans,cur+cur2*cc.b);
		}
		/*llo mi=-it[0];
		llo cur=0;
		for(llo i=1;i<n;i++){
			cur+=it[i]*it[0];
		}
		llo cur2=it[0]*(n-1);
		for(llo i=1;i<n;i++){
			cur2+=it[i];
		}
	
		ans=max(ans,mi*cur2+cur);
		
		mi=it[n-1];
		cur=0;
		for(llo i=1;i<n;i++){
			cur+=it[i-1]*it[n-1];
		}
		cur2=it[n-1]*(n-1);
		for(llo i=1;i<n;i++){
			cur2+=it[i-1];
		}
		ans=max(ans,mi*cur2+cur);*/

		cout<<ans<<endl;
	}






	return 0;
}