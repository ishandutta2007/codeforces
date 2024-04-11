#include<bits/stdc++.h>
const int N=1000005;
using namespace std;

int n,m;

void solve(){
	cin>>n>>m;
	int s=n*m;
	string S;cin>>S;
	vector<int> fst(m,s);
	vector<int> res(s),sum(s); 
	for(int i=0;i<s;i++){
		if(S[i]=='1'){
			fst[i%m]=min(fst[i%m],i);
		}
	}
	for(int i=0;i<m;i++)
		if(fst[i]!=s)
			res[fst[i]]++;
	for(int i=1;i<s;i++)
		res[i]+=res[i-1];
	vector<pair<int,int>> A;
	int l=-12,r=-12;
	for(int i=0;i<s;i++){
		if(S[i]=='1'){
			if(i>r+1){
				if(r>=0)A.push_back({l,r});
				l=i;
			}
			r=i+m-1;
		}
	}
	if(r>=0)A.push_back({l,r});
	for(auto x:A){
		if(x.first<s)sum[x.first]++;
		else break;
		if(x.second+1<s)sum[x.second+1]--;
		else break;
	}
	vector<int> ss(m);
	for(int i=0;i<s;i++)
		ss[i%m]+=sum[i],sum[i]=ss[i%m];
	for(int i=1;i<s;i++)
		sum[i]+=sum[i-1];
//	for(int i=0;i<s;i++)
//		cout<<res[i]<<' ';cout<<endl;
//	for(int i=0;i<s;i++)
//		cout<<sum[i]<<' ';cout<<endl;
	
	for(int i=0;i<s;i++)
		cout<<res[i]+sum[i]<<' ';
	cout<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}