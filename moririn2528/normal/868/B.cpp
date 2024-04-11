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

bool used[2];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int x,y;
	cin>>a>>b>>c;
	cin>>x>>y;
	if(x>y)swap(x,y);
	if(x<=a && a<y)used[0]=true;
	else used[1]=true;
	x*=5,y*=5;

	if(x<=b && b<y)used[0]=true;
	else used[1]=true;
	if(x<=c && c<y)used[0]=true;
	else used[1]=true;
	if(!used[0] || !used[1])cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}