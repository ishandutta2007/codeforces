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

vector<int> v1[200];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	m=100;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		a--;
		v1[a].push_back(i);
	}
	string sa(n,'A');
	a=0;
	for(i=0;i<m;i++){
		if(v1[i].size()==1){
			if(a%2)sa[v1[i][0]]='B';
			a++;
		}
	}
	for(i=0;i<m;i++){
		if(v1[i].size()>=3){
			if(a%2){
				sa[v1[i][0]]='B';
				a++;
			}
		}
	}
	if(a%2==0){
		cout<<"YES"<<endl;
		cout<<sa<<endl;
	}
	else cout<<"NO"<<endl;
}