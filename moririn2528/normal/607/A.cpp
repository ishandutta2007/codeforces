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

int dp[110000];
vector<P> v1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b;
		v1.push_back(make_pair(a,b));
	}
	sort(v1.begin(),v1.end());
	for(i=0;i<n;i++){
		a=v1[i].first-v1[i].second;
		auto itr=lower_bound(v1.begin(),v1.end(),make_pair(a,0));
		if(itr==v1.begin())dp[i]=i;
		else{
			itr--;
			b=distance(v1.begin(),itr);
			dp[i]=dp[b]+i-b-1;
		}
	}
	a=n;
	for(i=0;i<n;i++){
		b=dp[i]+n-i-1;
		a=min(a,b);
	}
	cout<<a<<endl;
}