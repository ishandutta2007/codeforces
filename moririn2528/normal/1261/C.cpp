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

vector<vector<int> > num,ca;
vector<string> ma;
vector<P> vs;
int n,m;

bool check(int x){
	int i,j,k;
	int a,b,c;
	ca.assign(n+2,vector<int>(m+2,0));
	vs.clear();
	for(i=x;i<n-x;i++){
		for(j=x;j<m-x;j++){
			a=num[i+x+1][j+x+1]-num[i+x+1][j-x]-num[i-x][j+x+1]+num[i-x][j-x];
			if(a)continue;
			vs.push_back(make_pair(i,j));
			ca[i-x][j-x]++,ca[i+x+1][j-x]--;
			ca[i-x][j+x+1]--,ca[i+x+1][j+x+1]++;
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			ca[i][j+1]+=ca[i][j];
		}
	}
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			ca[j+1][i]+=ca[j][i];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(ma[i][j]=='X' && ca[i][j]==0)return false;
			if(ma[i][j]=='.' && ca[i][j]>0)return false;
		}
	}
	return true;
}

char ct[1000005];

int main(){
	int i,j,k;
	int a,b,c;
	scanf("%d%d",&n,&m);
	num.assign(n+2,vector<int>(m+2,0));
	string sa;
	for(i=0;i<n;i++){
		scanf("%s",ct);
		sa=ct;
		ma.push_back(sa);
		for(j=0;j<m;j++){
			num[i+1][j+1]=num[i][j+1]+num[i+1][j]-num[i][j];
			if(sa[j]=='.')num[i+1][j+1]++;
		}
	}
	int t[3]={0,min(n,m)/2+2};
	while(t[1]-t[0]>1){
		t[2]=(t[0]+t[1])/2;
		if(check(t[2]))t[0]=t[2];
		else t[1]=t[2];
		//array_show(t,3);
	}
	check(t[0]);
	cout<<t[0]<<endl;
	ma.assign(n,string(m,'.'));
	for(auto node:vs){
		ma[node.first][node.second]='X';
	}
	for(i=0;i<n;i++){
		printf("%s\n",ma[i].c_str());
	}
}