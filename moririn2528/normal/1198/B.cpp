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

int t[200005];
int q[200005][3];
int s[200005];

int main(){
	int i,j,k;
	int a,b,c;
	int n,m;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>q[i][0];
		if(q[i][0]==1){
			cin>>q[i][1]>>q[i][2];
			q[i][1]--;
		}else cin>>q[i][1];
	}
	a=-1;
	memset(s,-1,sizeof(s));
	for(i=m-1;i>=0;i--){
		if(q[i][0]==1){
			b=q[i][1];
			if(s[b]!=-1)continue;
			if(q[i][2]<a)s[b]=a;
			else s[b]=q[i][2];
		}else if(a<q[i][1])a=q[i][1];
	}
	for(i=0;i<n;i++){
		if(s[i]!=-1)continue;
		if(t[i]<a)s[i]=a;
		else s[i]=t[i];
	}
	array_show(s,n);
}