#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
LL dis(P a,P b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
void read(P &x){
	cin>>x.first>>x.second;
}
const int N=100;
P p[N];
int main(){
	ios::sync_with_stdio(false);
	read(p[0]);
	LL ax,ay,bx,by;
	cin>>ax>>ay>>bx>>by;
	P s;
	read(s);
	LL t;
	cin>>t;
	int n=0;
	while(dis(p[n],P(0,0))<(LL)3e16){
		n++;
		p[n]=P(p[n-1].first*ax+bx,p[n-1].second*ay+by);
	}
	// cerr<<n<<endl;
	int ans=0;
	for(int i=0;i<n;i++)for(int j=i;j<n;j++)for(int k=i;k<=j;k++){
		LL lc=dis(p[k],p[i]),rc=dis(p[k],p[j]);
		LL cost=dis(s,p[k])+lc+rc+min(lc,rc);
		if(cost<=t){
			ans=max(ans,j-i+1);
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}