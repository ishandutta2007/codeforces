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

vector<LL> v1,v2,v3;

void vec_add(vector<LL> &va,vector<LL>& vb,LL a,LL l){
	LL ad=1;
	for(auto node:va){
		ad=1;
		while(ad+node<=l){
			vb.push_back(ad+node);
			if(l/a<ad)break;
			ad*=a;
		}
	}
}

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	LL r,l;
	LL s=0;
	cin>>n>>m>>r>>l;
	v1.push_back(0);
	vec_add(v1,v2,n,l);
	vec_add(v2,v3,m,l);
	sort(v3.begin(),v3.end());
	v3.push_back(l+1);
	for(i=0;i<v3.size() && v3[i]<r;i++);
	a=r-1,s=0;
	for(;i<v3.size();i++){
		b=v3[i]-a-1;
		s=max(s,b);
		a=v3[i];
	}
	cout<<s<<endl;
}