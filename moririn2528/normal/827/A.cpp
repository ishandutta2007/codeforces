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

char ca[2000005];
string sa;
vector<string> vs;
int num[2000005];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	b=0;
	memset(num,-1,sizeof(num));
	for(i=0;i<n;i++){
		cin>>sa;
		vs.push_back(sa);
		cin>>m;
		for(j=0;j<m;j++){
			cin>>a;
			a--;
			if(num[a]==-1)num[a]=i;
			else if(sa.size()>vs[num[a]].size())num[a]=i;
			b=max(b,a+(int)sa.size());
		}
	}
	ca[b]='\0';
	a=-1;
	for(i=0;i<b;i++){
		if(num[i]!=-1){
			if(a==-1 || ((int)vs[num[a]].size()-i+a)<(int)(vs[num[i]].size()))a=i;
		}
		if(a==-1 || vs[num[a]].size()<=i-a)ca[i]='a';
		else ca[i]=vs[num[a]][i-a];
	}
	cout<<ca<<endl;
}