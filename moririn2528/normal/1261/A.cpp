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

string sa,sb;
vector<P> vs;

int main(){
	int n,m,t;
	int i,j,k;
	int a,b,c;
	cin>>t;
	while(t--){
		cin>>n>>m;
		cin>>sa;
		sb=sa;
		m--;
		vs.clear();
		for(i=0;i<n;i++){
			if(i<n/2-m)sb[i]='(';
			else if(i<n-2*m)sb[i]=')';
			else if(i%2==0)sb[i]='(';
			else sb[i]=')';
		}
		//cout<<sb<<endl;
		for(i=0;i<n;i++){
			if(sa[i]==sb[i])continue;
			for(j=i+1;j<n && sa[i]==sa[j];j++);
			reverse(sa.begin()+i,sa.begin()+j+1);
			vs.push_back(make_pair(i+1,j+1));
		}
		cout<<vs.size()<<endl;
		for(auto node:vs){
			cout<<node.first<<" "<<node.second<<endl;
		}
	}
}