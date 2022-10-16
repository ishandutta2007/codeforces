#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int x[N];

void solve(){
	int n,m;string s[11];
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>x[i];
	for(int i=0;i<n;i++)cin>>s[i];
	vector<int> ans(m);
	int na=-1;
	for(int i=0;i<1<<n;i++){
		vector<int> a[21];
		for(int k=0;k<m;k++){
			int S=0;
			for(int p=0;p<n;p++)
				if(s[p][k]=='1')
					if(i>>p&1)S--;
					else S++;
			a[S+n].push_back(k);
		}
		int nw=m;
		int nas=0;
		vector<int> S(n),nA(m);
		for(int o=2*n;o>=0;o--){
			for(auto x:a[o]){
				for(int p=0;p<n;p++)
					if(s[p][x]=='1')
						S[p]+=nw;
				nA[x]=nw--; 
			}
		} 
		for(int p=0;p<n;p++)
			nas+=abs(S[p]-x[p]);
		int fl=1;
		if(na<nas)ans=nA,na=nas;
	}
	for(auto x:ans)cout<<x<<' ';cout<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}