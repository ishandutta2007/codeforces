#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[300005],pos[300005];
vector<pair<int,int> >ans;
void add(int x,int y){
	ans.push_back(make_pair(x,y));
	swap(a[x],a[y]);
	pos[a[x]]=x;
	pos[a[y]]=y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=n;i++){
		if(pos[i]==i)continue;
		if(abs(pos[i]-i)>=n/2){
			add(i,pos[i]);
		}else if(pos[i]<=n/2&&i<=n/2){
			add(i,n);
			add(pos[i],n);
			add(i,n);
		}else if(pos[i]>n/2&&i>n/2){
			add(i,1);
			add(pos[i],1);
			add(i,1);
		}else{
			int mn=min(i,pos[i]),mx=max(i,pos[i]);
			add(mn,n);
			add(1,mx);
			add(1,n);
			add(mn,n);
			add(1,mx);
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto p:ans)printf("%d %d\n",p.first,p.second);
	return 0;
}