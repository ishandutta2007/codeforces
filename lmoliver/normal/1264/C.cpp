#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=998244353;
int add(int a,int b){return (a+b)%MOD;}
int sub(int a,int b){return (a-b+MOD)%MOD;}
int mul(int a,int b){return (LL)a*b%MOD;}
int sqr(int a){return mul(a,a);}
int ksm(int a,int b){return b==0?1:mul(sqr(ksm(a,b>>1)),b&1?a:1);}
int inv(int a){return ksm(a,MOD-2);}
const int INV100=inv(100);
const int N=200200;
// (x*a+b)*c+d=x*a*c+b*c+d
// (a,b)+(c,d)=(a*c,b*c+d)
typedef pair<int,int> P;
P operator*(P a,P b){
	return P{mul(a.first,b.first),add(mul(a.second,b.first),b.second)};
}
P operator/(P s,P a){
	int c=mul(s.first,inv(a.first));
	int d=sub(s.second,mul(a.second,c));
	return P{c,d};
}
int operator*(P a,int x){
	return add(mul(a.first,x),a.second);
}
int p[N];
P s[N];
set<int> us;
int main(){
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	s[0]=P{1,0};
	us.insert(1);
	us.insert(n+1);
	for(int i=1;i<=n;i++){
		cin>>p[i];
		int w=mul(100,inv(p[i]));
		// cerr<<p[i]<<" "<<w<<endl;
		s[i]=s[i-1]*P{w,w};
	}
	int ans=s[n]*0;
	// cerr<<ans<<endl;
	while(q--){
		int u;
		cin>>u;
		if(us.count(u)){
			auto it=us.find(u);
			P z=s[*it-1];
			it++;
			P x=s[*it-1];
			it--;
			it--;
			P y=s[*it-1];
			ans=add(ans,x/y*0);
			ans=sub(ans,x/z*0);
			ans=sub(ans,z/y*0);
			us.erase(u);
		}
		else{
			auto it=us.lower_bound(u);
			P x=s[*it-1];
			it--;
			P y=s[*it-1];
			P z=s[u-1];
			ans=sub(ans,x/y*0);
			ans=add(ans,x/z*0);
			ans=add(ans,z/y*0);
			us.insert(u);
		}
		cout<<ans<<endl;
	}
	return 0;
}