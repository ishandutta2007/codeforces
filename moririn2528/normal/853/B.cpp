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

LL cost[2][100005];
LL tes[100005];
vector<tuple<int,int,int,int> > v1;

int main(){
	int n,m,p;
	int i,j,k;
	LL a,b,c,d;
	cin>>n>>m>>p;
	p++;
	for(i=0;i<m;i++){
		cin>>a>>b>>c>>d;
		v1.push_back(make_tuple(a,b,c,d));
	}
	sort(v1.begin(),v1.end());
	LL num=n,su=0;
	for(i=0;i<m;i++){
		tie(ignore,a,b,c)=v1[i];
		if(b){
			if(num==0)cost[0][i]=su;
			continue;
		}

		su-=tes[a];
		if(tes[a]==0)num--,tes[a]=c;
		else tes[a]=min(tes[a],c);
		su+=tes[a];

		if(num==0)cost[0][i]=su;
	}
	num=n,su=0;
	memset(tes,0,sizeof(tes));
	for(i=m-1;i>=0;i--){
		tie(ignore,b,a,c)=v1[i];
		if(b){
			if(num==0)cost[1][i]=su;
			continue;
		}

		su-=tes[a];
		if(tes[a]==0)num--,tes[a]=c;
		else tes[a]=min(tes[a],c);
		su+=tes[a];

		if(num==0)cost[1][i]=su;
	}
	su=-1;
	for(i=0,j=0;i<m;i++){
		a=get<0>(v1[i]);
		if(cost[0][i]==0)continue;
		for(;j<m && get<0>(v1[j])<a+p;j++);
		if(j==m || cost[1][j]==0)break;
		if(su==-1)su=cost[0][i]+cost[1][j];
		else su=min(su,cost[0][i]+cost[1][j]);
	}
	cout<<su<<endl;
}