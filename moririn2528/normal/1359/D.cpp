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

int t[110000];
int ts[110000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int s=0;
	vector<P> v1;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
		ts[i+1]=ts[i]+t[i];
	}
	for(i=n-1;i>=0;i--){
		b=ts[i+1];
		while(!v1.empty()){
			a=v1.back().first;
			if(t[a]>t[i])break;
			b=max(b,v1.back().second);
			v1.pop_back();
		}
		v1.push_back(make_pair(i,b));
		m=v1.size();
		for(j=m-1;j>=0;j--){
			a=v1[j].second-ts[i]-t[v1[j].first];
			s=max(s,a);
		}
	}
	cout<<s<<endl;
}