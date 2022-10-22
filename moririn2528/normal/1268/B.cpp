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

vector<P> v1;

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	b=0;
	for(i=0;i<n;i++){
		cin>>a;
		b+=a;
		if(v1.empty())v1.push_back(make_pair(a,1));
		else{
			P& pa=v1.back();
			if(pa.first==a)pa.second++;
			else v1.push_back(make_pair(a,1));
		}
	}
	reverse(v1.begin(),v1.end());
	a=0;
	for(i=0;i<v1.size();i++){
		if(v1[i].second%2==0)continue;
		if((v1[i].first-a)%2==0){
			if(a>0)a--;
		}else a++;
	}
	b-=a/2;
	cout<<b/2<<endl;
}