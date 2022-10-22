#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pr;
const int MAXN=5e4+5;
int n,m,a[MAXN],k,b[MAXN];
vector<pr> GetVec(int n,int *a){
	vector<pr> res;
	for(int i=1; i<=n; i++){
		ll t=1;
		while(a[i]%m==0)
			a[i]/=m,t*=m;
		if(!res.empty()&&res.back().first==a[i]) res[res.size()-1].second+=t;
		else res.emplace_back(a[i],t);
	}
	return res;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		scanf("%d",&k);
		for(int i=1; i<=k; i++)
			scanf("%d",b+i);
		if(GetVec(n,a)==GetVec(k,b)) puts("Yes");
		else puts("No");
	}
	return 0;
}