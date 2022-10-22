#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

vector<int> v1;
vector<P> va,vq;
vector<int> vs;
vector<vector<int>> dp(6e6,vector<int>(10,-1));
vector<int> best(20,-1);
const int N=8;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int vi=0;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		vq.push_back(make_pair(a,b));
		va.push_back(make_pair(b,i));
	}
	sort(va.rbegin(),va.rend());
	vs.assign(m,0);
	vector<int> v2;
	for(i=0;i<n;i++){
		v2.clear();
		b=v1[i];
		for(j=2;j<2500;j++){
			if(b==1)break;
			for(a=0;b%j==0;a++,b/=j);
			if(a%2)v2.push_back(j);
		}
		if(b>1)v2.push_back(b);
		c=v2.size();
		for(j=0;j<(1<<c);j++){
			a=1,b=0;
			for(k=0;k<c;k++){
				if(j&(1<<k))a*=v2[k];
				else b++;
			}
			for(k=0;k<N;k++){
				best[b+k]=max(best[b+k],dp[a][k]);
			}
			dp[a][b]=i;
		}
		while(!va.empty() && va.back().first==i){
			c=va.back().second,va.pop_back();
			a=vq[c].first;
			for(j=0;j<2*N;j++){
				if(a<=best[j])break;
			}
			vs[c]=j;
		}
	}
	for(auto num:vs){
		cout<<num<<endl;
	}
}