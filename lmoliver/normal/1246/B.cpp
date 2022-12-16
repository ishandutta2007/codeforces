#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef map<int,int> MII;
const int N=100100;
MII gg(int x){
	MII ans;
	ans.clear();
	for(LL i=2;i*i<=x;i++){
		while(x%i==0){
			x/=i;
			ans[i]++;
		}
	}
	if(x!=1){
		ans[x]++;
	}
	return ans;
}
map<MII,int> qaq;
int main(){
	qaq.clear();
	int n,k;
	scanf("%d%d",&n,&k);
	LL ans=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		MII f=gg(x);
		MII g;
		g.clear();
		vector<int> z;
		for(MII::iterator it=f.begin();it!=f.end();++it){
			// cerr<<it->first<<" "<<it->second<<endl;
			it->second%=k;
			if(it->second!=0){
				g[it->first]=(k-it->second)%k;
			}
			else{
				z.push_back(it->first);
			}
		}
		for(vector<int>::iterator it=z.begin();it!=z.end();++it){
			f.erase(*it);
		}
		// for(MII::iterator it=f.begin();it!=f.end();++it){
		// 	cerr<<it->first<<": "<<it->second<<endl;
		// }
		// for(MII::iterator it=g.begin();it!=g.end();++it){
		// 	cerr<<it->first<<": "<<it->second<<endl;
		// }
		ans+=qaq[g];
		qaq[f]+=1;
	}
	cout<<ans<<endl;
	return 0;
}