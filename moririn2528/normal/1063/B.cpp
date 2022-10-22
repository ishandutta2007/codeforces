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

string sa;
bool used[2200][2200];
LL num[2200][2200];
deque<tuple<LL,LL,LL> > q1;

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c,p,q;
	LL x,y;
	cin>>n>>m;
	cin>>p>>q;
	p--,q--;
	cin>>x>>y;
	memset(num,-1,sizeof(num));
	for(i=0;i<n;i++){
		cin>>sa;
		for(j=0;j<m;j++){
			if(sa[j]=='*'){
				used[i][j]=true;
			}
		}
	}
	q1.push_back(make_tuple(p,q,0));
	while(!q1.empty()){
		tie(a,b,c)=q1.front(),q1.pop_front();
		if(a<0 || a>=n || b<0 || b>=m)continue;
		if(used[a][b])continue;
		used[a][b]=true;
		num[a][b]=c;
		q1.push_front(make_tuple(a-1,b,c));
		q1.push_front(make_tuple(a+1,b,c));
		q1.push_back(make_tuple(a,b-1,c+1));
		q1.push_back(make_tuple(a,b+1,c+1));
	}
	int s=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(num[i][j]==-1)continue;
			a=num[i][j];//r+l
			b=q-j;//l-r
			if(a+b<=2*x && a-b<=2*y)s++;
		}
	}
	cout<<s<<endl;
}