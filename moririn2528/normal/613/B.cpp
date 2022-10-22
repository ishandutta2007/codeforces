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

vector<pair<LL,LL> > v1;

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	LL A,cm,cf;
	LL s[5]={0,(LL)1<<60,0};
	LL sum[5]={0};
	cin>>n>>A>>cf>>cm>>m;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(make_pair(a,i));
		sum[0]+=A-a;
	}
	sort(v1.begin(),v1.end());
	if(sum[0]<=m){
		cout<<cf*n+cm*A<<endl;
		vector<LL> va(n,A);
		array_show(va);
		return 0;
	}
	j=0;
	v1.push_back(make_pair(A,0));
	for(i=0;i<n;i++){
		sum[0]-=A-v1[i].first;
		if(sum[0]>m)continue;
		for(;j<=i-1;j++){
			a=sum[1]+(v1[j+1].first-v1[j].first)*(j+1);
			if(a>m-sum[0])break;
			sum[1]=a;
		}
		a=m-sum[0]-sum[1];
		a=v1[j].first+a/(j+1);
		a=min(a,A);
		b=(n-i-1)*cf+a*cm;
		if(b>s[0])s[0]=b,s[1]=i,s[2]=a;
	}
	cout<<s[0]<<endl;
	v1.pop_back();
	vector<LL> vs(n);
	for(i=0;i<n;i++){
		if(i>s[1])v1[i].first=A;
		v1[i].first=max(v1[i].first,s[2]);
		vs[v1[i].second]=v1[i].first;
	}
	array_show(vs);
}