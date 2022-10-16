#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
bitset<200002>mask[4],ans;
int to[222];
int dif[200005][4];
string s,t;
int a,b,k;
void add(int pos,int l,int r){
	l=max(l,0);r=min(r,200001);r=max(r,l);
	dif[l][pos]++;dif[r+1][pos]--;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b>>k>>s>>t;
	ans.set();to['A']=0;to['T']=1;to['G']=2;to['C']=3;
	for(int i=0;i<4;i++)mask[i].reset();
	for(int i=0;i<s.size();i++){
		int num=to[s[i]];
		add(num,i-k,i+k);
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<4;j++){
			if(i)dif[i][j]+=dif[i-1][j];
			if(dif[i][j])mask[j].set(i);
		}
	}
	for(int i=0;i<t.size();i++)ans&=(mask[to[t[i]]]>>i);
	cout<<ans.count()<<endl;
	return 0;
}