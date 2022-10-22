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
#include<set>
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

void init(){
	
}

void solve(){
	LL n,m,p;
	int i,j,k;
	LL a,b,c;
	string sa;
	set<LL> m1;
	cin>>n>>m;
	LL cnt=((LL)1<<(m-1))-1;
	for(i=0;i<n;i++){
		cin>>sa;
		a=0;
		for(j=0;j<m;j++){
			a*=2;
			if(sa[j]=='1')a++;
		}
		m1.insert(a);
		if(sa[0]=='0')cnt--;
	}
	p=((LL)1<<m)-n;
	p=(p-1)/2;
	LL s=((LL)1<<(m-1))-1;
	while(s>=0 && m1.find(s)!=m1.end())s--;
	while(cnt<p){
		s++;
		if(m1.find(s)==m1.end())cnt++;
	}
	while(cnt>p){
		s--;
		if(m1.find(s)==m1.end())cnt--;
	}
	string ss(m,'0');
	for(j=0;j<m;j++){
		if(s&((LL)1<<(m-j-1)))ss[j]='1';
	}
	cout<<ss<<endl;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		solve();
	}
}