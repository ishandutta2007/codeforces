//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[200001];
llo n,m;
bool check(llo mid){
	pair<llo,llo> cur={0,0};
	llo su=0;
	for(llo i=0;i<n;i++){
		su+=max(it[i]-cur.b,(llo)0);
		cur.a++;
		if(cur.a==mid){
			cur.a=0;
			cur.b+=1;
		}
	}
	return su>=m;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		it[i]=-it[i];
	}
	sort(it,it+n);
	for(llo i=0;i<n;i++){
		it[i]=-it[i];
	}
	llo low=1;
	llo high=n;
	if(check(n)==false){
		cout<<-1<<endl;
		return 0;
	}
	while(low<high-1){
		llo mid=(low+high)/2;
		if(check(mid)){
			high=mid;
		}
		else{
			low=mid;
		}
	}
	llo ans=high;
	if(check(low)){
		ans=min(ans,low);
	}
	cout<<ans<<endl;
	



 
	return 0;
}