//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[2][300001];
llo pre[300001][2];
llo pre2[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[0][i];
	}
	for(llo i=0;i<n;i++){
		cin>>it[1][i];
	}
	
	llo ans=0;
	for(llo i=0;i<n;i++){
		ans+=it[0][i]*i;
	}
	for(llo i=n-1;i>=0;i--){
		ans+=(it[1][i]*(n-1-i+n));
	}
	for(llo i=n-1;i>=0;i--){
		pre[i][1]=pre2[i+1]+pre[i+1][1]+it[0][i]*((n-1-i)*2+1);
		pre[i][0]=pre2[i+1]+pre[i+1][0]+it[1][i]*((n-1-i)*2+1);
		pre2[i]=pre2[i+1]+it[0][i]+it[1][i];
	}
	//cout<<pre[2][1]<<":"<<pre[1][1]<<endl;
	llo cur=0;
	llo su=0;
	for(llo i=0;i<n;i++){
		if(i%2==0){
			su+=it[0][i]*cur;
			cur++;
			su+=it[1][i]*cur;
			cur++;
			//cout<<su<<":"<<endl;
			//cout<<pre[i+1][1]<<":"<<endl;
			ans=max(ans,su+pre[i+1][1]+pre2[i+1]*cur);
			//cout<<su+pre[i+1][1]+pre2[i+1]*cur<<endl;
		}
		else{
			su+=it[1][i]*cur;
			cur++;
			su+=it[0][i]*cur;
			cur++;
			//cout<<su+pre[i+1][0]+pre2[i+1]*cur<<endl;
			ans=max(ans,su+pre[i+1][0]+pre2[i+1]*cur);
		}
	}
	cout<<ans<<endl;





 
	return 0;
}