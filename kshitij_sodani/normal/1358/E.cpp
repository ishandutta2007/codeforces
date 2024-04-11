#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
llo n;
llo x;
llo it[500001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<(n+1)/2;i++){
		cin>>it[i];
	}
	cin>>x;
	for(llo i=(n+1)/2;i<n;i++){
		it[i]=x;
	}
	llo pre[(n+1)/2];
	pre[0]=0;
	for(llo i=0;i<(n+1)/2;i++){
		pre[0]+=it[i];
	}
	for(llo j=1;j<(n/2)+1;j++){
		pre[j]=pre[j-1];
		pre[j]+=x;
		pre[j]-=it[j-1];
	}
	for(llo i=1;i<(n/2)+1;i++){
		pre[i]=min(pre[i],pre[i-1]);
	}
	llo co=0;
	llo ans=-1;
	for(llo j=n/2;j>=0;j--){
		if(pre[j]+co*x>0){
			ans=-(j+1-n-1);
			break;
		}
		co+=1;
	}
	cout<<ans<<endl;

	return 0;
}