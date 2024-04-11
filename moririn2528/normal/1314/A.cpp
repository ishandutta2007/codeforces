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

LL t[220000][2];
priority_queue<LL> q1;
LL q1_sum;

int main(){
	int n,m;
	LL i,j,k;
	LL a,b,c;
	LL s=0;
	cin>>n;
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			cin>>t[j][i];
		}
	}
	vector<P> v1;
	for(i=0;i<n;i++){
		v1.push_back(make_pair(t[i][0],t[i][1]));
	}
	sort(v1.rbegin(),v1.rend());
	for(i=0;!v1.empty() || !q1.empty();i++){
		while(!v1.empty()){
			a=v1.back().first;
			if(a!=i)break;
			a=v1.back().second;
			q1.push(a);
			q1_sum+=a;
			v1.pop_back();
		}
		if(!q1.empty()){
			a=q1.top(),q1.pop();
			q1_sum-=a;
		}
		if(q1.empty() && !v1.empty()){
			i=v1.back().first-1;
		}
		s+=q1_sum;
	}
	cout<<s<<endl;
}