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

vector<int> v1;
bool used[200005];

int main(){
	int n,m,p;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m>>p;
	for(i=0;i<n*m;i++){
		cin>>a;
		v1.push_back(a);
	}
	sort(v1.begin(),v1.end());
	auto itr=upper_bound(v1.begin(),v1.end(),v1[0]+p);
	a=distance(v1.begin(),itr);
	b=0,c=0;
	if(a<n){
		cout<<0<<endl;
		return 0;
	}
	for(i=0;i<a;i+=m){
		if(b==n)break;
		b++,c+=v1[i];
		used[i]=true;
	}
	for(i=a-1;i>=0;i--){
		if(b==n)break;
		if(used[i])continue;
		b++,c+=v1[i];
	}
	cout<<c<<endl;
}