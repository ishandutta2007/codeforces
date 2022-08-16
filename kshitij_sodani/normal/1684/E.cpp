#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int it[100001];
int co[300001];
int pre[300001];
int freq[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		map<int,int> ss;
		for(int i=0;i<=3*n;i++){
			co[i]=0;
			pre[i]=0;
		}
		for(int i=0;i<=300;i++){
			freq[i]=0;
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
			if(it[i]>n){
				ss[it[i]]++;
			}
		}
		map<int,int> tt2;
		int ind=n+1;
		for(auto j:ss){
			tt2[j.a]=ind;
			ind++;
		}
		for(int i=0;i<n;i++){
			if(it[i]>n){
				it[i]=tt2[it[i]];
			}
		}
		for(int i=0;i<n;i++){
			co[it[i]]++;
		}
		vector<int> tt;
		for(int i=0;i<=3*n;i++){
			if(co[i]>0){
				tt.pb(co[i]);
			}
		}
		sort(tt.begin(),tt.end());
		int ans=tt.size();
		int le=k;
		for(int i=0;i+1<tt.size();i++){
			if(le>=tt[i]){
				le-=tt[i];
				ans--;
			}
		}
		for(int i=0;i<=3*n;i++){
			pre[i]=0;
			if(co[i]==0){
				pre[i]=1;

			}
			if(i>0){
				pre[i]+=pre[i-1];
			}
		}
		//min ans assuming mex=0
		const int bb=300;
		vector<int> dd;
		int zz=0;
		for(int i=3*n;i>=1;i--){
			if(co[i]>0){
				zz++;
				if(co[i]<bb){
					freq[co[i]]++;
				}
				else{
					dd.pb(co[i]);
					sort(dd.begin(),dd.end());
				}
			}
			int cur=zz;
			int le=k;
			for(int j=1;j<bb;j++){
				llo xx=le/j;
				if(xx>freq[j]){
					xx=freq[j];
				}
				cur-=xx;
				le-=xx*j;
			}

			for(auto j:dd){
				if(le>=j){
					cur-=j;
					cur--;
				}
			}
			if(i<=n){
				if(pre[i-1]>k){
					continue;
				}
				ans=min(ans,cur);
			}
		}
		cout<<ans<<endl;






		for(int i=0;i<=3*n;i++){
			co[i]=0;
			pre[i]=0;
		}
		for(int i=0;i<=300;i++){
			freq[i]=0;
		}
	}


	







	return 0;
}