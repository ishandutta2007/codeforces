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

int col[1100][1100];
LL dis[1100][1100];
deque<tuple<int,int,int>> q1;
int n,m,q;

bool check2(int x,int y,int x2,int y2){
	if(x2<0 || x2>=n || y2<0 || y2>=m)return false;
	if(col[x][y]==col[x2][y2])return true;
	return false;
}
bool check(int x,int y){
	int i,j;
	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if((i+j+2)%2==0)continue;
			if(check2(x,y,x+i,y+j))return true;
		}
	}
	return false;
}

int main(){
	int i,j,k;
	LL a,b,c,d;
	string sa;
	cin>>n>>m>>q;
	for(i=0;i<n;i++){
		cin>>sa;
		for(j=0;j<m;j++){
			col[i][j]=(int)sa[j]-(int)'0';
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(check(i,j))q1.push_back(make_tuple(i,j,0));
		}
	}
	memset(dis,-1,sizeof(dis));
	while(!q1.empty()){
		tie(a,b,c)=q1.front(),q1.pop_front();
		if(a<0 || a>=n || b<0 || b>=m)continue;
		if(dis[a][b]!=-1)continue;
		dis[a][b]=c;
		for(i=-1;i<=1;i++){
			for(j=-1;j<=1;j++){
				if((i+j+2)%2==0)continue;
				if(a+i<0 || a+i>=n || b+j<0 || b+j>=m)continue;
				if(dis[a+i][b+j]!=-1)continue;
				if(col[a+i][b+j]==col[a][b])q1.push_front(make_tuple(a+i,b+j,c));
				else q1.push_back(make_tuple(a+i,b+j,c+1));
			}
		}
		q1.push_back(make_tuple(a+1,b,c+1));
	}

	for(i=0;i<q;i++){
		cin>>a>>b>>c;
		a--,b--;
		if(dis[a][b]==-1 || dis[a][b]>=c){
			cout<<col[a][b]<<endl;
		}else{
			c-=dis[a][b];
			c%=2;
			cout<<(col[a][b]+c)%2<<endl;
		}
	}
}