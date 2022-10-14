#include<bits/stdc++.h>
using namespace std;
int const N=1000010,M=10000001;
int n,p1,p2,a[N],v[N];
vector<int>p[M],t;
long long ans=LLONG_MAX;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[a[i]].size()<2&&(p[a[i]].push_back(i),1);
	for(int i=1;i<M;i++){
		t.clear();
		for(int j=i;j<M;j+=i){
			for(int x:p[j])
				t.push_back(x);
			if(t.size()>1)
				break;
		}
		if(t.size()<2)
			continue;
		long long res=1ll*a[t[0]]*a[t[1]]/i;
		if(res<ans)
			ans=res,p1=t[0],p2=t[1];
	}
	if(p1>p2)
		swap(p1,p2);
	cout<<p1<<" "<<p2<<"\n";
}