#include<bits/stdc++.h>
#define int long long 
using namespace std;
int const K=1000000,N=K+10;
int n,m,ans=1,tr[N];
struct node{
	int t,x,y;
	int operator<(const node&rhs)const{
		return t<rhs.t;
	}
};
vector<node>q1,q2;
void add(int x,int y){
	for(x++;x<N;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	int res=0;
	for(x++;x;x&=x-1)res+=tr[x];
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	while(n--){
		int a,b,c;cin>>a>>b>>c;
		ans+=c-b==K;
		q1.push_back({b-1,a,1});
		q1.push_back({c,a,-1});
	}
	while(m--){
		int a,b,c;cin>>a>>b>>c;
		ans+=c-b==K;
		q2.push_back({a,b,c}); 
	}
	sort(q1.begin(),q1.end());
	sort(q2.begin(),q2.end());
	for(int i=1,p1=0,p2=0;i<=K;i++){
		while(p1<q1.size()&&q1[p1].t<i)
			add(q1[p1].x,q1[p1].y),p1++;
		while(p2<q2.size()&&q2[p2].t<=i)
			ans+=ask(q2[p2].y)-ask(q2[p2].x-1),p2++;
	}
	cout<<ans<<"\n";
}