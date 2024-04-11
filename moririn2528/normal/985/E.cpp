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
int num[1100005];

int main(){
	int n,m,p;
	int i,j,k;
	int a,b,c;
	bool flag=false;
	cin>>n>>m>>p;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	sort(v1.begin(),v1.end());
	num[0]=1,num[1]=-1;
	b=0;
	for(i=0;i<=n-m;i++){
		b+=num[i];
		if(b==0)continue;
		auto itr=upper_bound(v1.begin(),v1.end(),v1[i]+p);
		a=distance(v1.begin(),itr)+1;
		if(a<i+m)continue;
		num[i+m]++,num[a]--;
		if(itr==v1.end())flag=true;
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}