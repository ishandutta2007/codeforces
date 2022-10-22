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
const LL MAX=1e6+3;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

int f[2][200005];
int go[200005];

int main(){
	int n,m;
	int ta,tb,p;
	int i,j,k;
	int a,b,c;
	int s=0;
	cin>>n>>m>>ta>>tb>>p;
	for(i=0;i<n;i++){
		cin>>f[0][i];
	}
	for(i=0;i<m;i++){
		cin>>f[1][i];
	}
	for(i=0,j=0;i<n;i++){
		for(;j<m;j++){
			if(f[0][i]+ta<=f[1][j])break;
		}
		go[i]=j;
	}
	for(i=0;i<=p;i++){
		if(i>=n || go[i]+p-i>=m){
			s=-1;break;
		}
		a=go[i]+p-i;
		s=max(s,f[1][a]+tb);
	}
	cout<<s<<endl;
}