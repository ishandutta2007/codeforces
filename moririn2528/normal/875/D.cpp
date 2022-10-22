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

int pos[200005][35][2];
int t[200005];
vector<P> v1;
map<int,int> m1;

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	int p,q;
	LL s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
		v1.push_back(make_pair(t[i],i));
	}
	for(i=0;i<30;i++){
		a=-1;
		for(j=0;j<n;j++){
			if(t[j]&(1<<i))a=j;
			pos[j][i][0]=a;
		}
		a=n;
		for(j=n-1;j>=0;j--){
			if(t[j]&(1<<i))a=j;
			pos[j][i][1]=a;
		}
	}
	s=n*(n-1)/2;
	m1[-1]=1,m1[n]=1;
	sort(v1.rbegin(),v1.rend());
	for(i=0;i<n;i++){
		a=v1[i].second;
		auto itr=m1.lower_bound(a);
		q=itr->first,p=(--itr)->first;
		m1[a]=1;
		for(j=0;j<30;j++){
			if(t[a]&(1<<j))continue;
			p=max(p,pos[a][j][0]),q=min(q,pos[a][j][1]);
		}
		if(q-p<=2)continue;
		s-=(a-p-1)*(q-a-1)+(q-p-2);
	}
	cout<<s<<endl;
}