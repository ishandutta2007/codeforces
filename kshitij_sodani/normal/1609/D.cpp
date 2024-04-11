//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int par[1001];
int ss[1001];
int find(int no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		par[i]=i;
		ss[i]=1;
	}

	for(int i=0;i<d;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		int x=find(aa);
		int y=find(bb);
		if(x!=y){
			par[x]=y;
			ss[y]+=ss[x];
		}
		vector<int> cc;
		int co=0;
		for(int j=0;j<n;j++){
			if(par[j]==j){
				co+=ss[j]-1;
				cc.pb(ss[j]);
			}
		}
		sort(cc.begin(),cc.end());
		reverse(cc.begin(),cc.end());
		int le=i+1-co;
		int ans=-1;
		for(int j=0;j<=le;j++){
			if(j==cc.size()){
				break;
			}
			ans+=cc[j];
		}
		cout<<ans<<endl;
	}



 
	return 0;
}