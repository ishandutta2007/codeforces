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

vector<int> path[200005];
int s[200005];
int t[200005];

bool check(int a,int p){
	if(t[a]==p)return true;
	if(t[a]!=0)return false;
	t[a]=p;
	for(int i=0;i<path[a].size();i++){
		if(!check(path[a][i],3-p))return false;
	}
	return true;
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		s[i]=a;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	bool bs=check(0,1);
	print_YES_NO(bs);
	if(!bs)return 0;
	for(i=0;i<m;i++){
		cout<<t[s[i]]-1;
	}
	cout<<endl;
}