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

int t[110000];
vector<vector<int> > v1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
		t[i]--;
	}
	for(i=0;i<n;i++){
		vector<int> va;
		a=i;
		while(t[a]!=-1){
			va.push_back(t[a]);
			b=t[a],t[a]=-1;
			a=b;
		}
		if(!va.empty())v1.push_back(va);
	}
	for(auto va:v1){
		if(va.size()==1){
			cout<<"YES"<<endl;
			a=va[0];
			for(i=0;i<n;i++){
				if(i==a)continue;
				cout<<a+1<<" "<<i+1<<endl;
			}
			return 0;
		}
	}
	b=1e9;
	for(auto va:v1){
		a=va.size();
		b=min(a,b);
		if(a%2==1){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(b>2){
		cout<<"NO"<<endl;
		return 0;
	}
	for(a=0;a<v1.size();a++){
		if(v1[a].size()==2)break;
	}
	cout<<"YES"<<endl;
	cout<<v1[a][0]+1<<" "<<v1[a][1]+1<<endl;
	for(i=0;i<v1.size();i++){
		if(i==a)continue;
		for(j=0;j<v1[i].size();j++){
			cout<<v1[a][j%2]+1<<" "<<v1[i][j]+1<<endl;
		}
	}
}