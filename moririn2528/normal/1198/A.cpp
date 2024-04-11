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
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

map<int,int> m1;
vector<LL> v1;

int main(){
	LL n,m;
	LL a,b,c;
	int i,j,k;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		m1[a]++;
	}
	m*=8;
	m/=n;
	a=1;
	for(i=0;i<m;i++){
		a*=2;
		if(n<a)break;
	}
	v1.push_back(0);
	for(auto itr=m1.begin();itr!=m1.end();itr++){
		b=v1.back()+itr->second;
		v1.push_back(b);
	}
	int s=INF;
	for(i=0;i<v1.size()-a;i++){
		b=n-(v1[i+a]-v1[i]);
		if(b<s)s=b;
	}
	if(s==INF)s=0;
	cout<<s<<endl;
}