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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=998244353;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

LL t[200005];// n!

vector<int> path[200005];
bool used[200005];

LL check(int a,bool mode=false){
	if(used[a])return -1;
	used[a]=true;
	LL s=1,sa=0,sc=0;
	for(int i=0;i<path[a].size();i++){
		sa=check(path[a][i],true);
		if(sa!=-1)s*=sa,sc++;
		if(s>=MAX)s%=MAX;
	}
	s*=t[sc];
	if(s>=MAX)s%=MAX;
	if(mode)s*=sc+1;
	if(s>=MAX)s%=MAX;
	return s;
}

int main(){
	LL n;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	t[0]=1;
	for(i=1;i<=n;i++){
		t[i]=t[i-1]*i;
		if(t[i]>=MAX)t[i]%=MAX;
	}
	a=check(0)*n;
	if(a>=MAX)a%=MAX;
	cout<<a<<endl;
}