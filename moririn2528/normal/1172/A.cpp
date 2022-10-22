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

int t[2][200005];
int p[200005][2];

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	cin>>n;
	a=-1;
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			cin>>t[i][j];
			if(i==1 && t[i][j]==1)a=j;
			if(t[i][j]!=0){
				p[t[i][j]-1][0]=i,p[t[i][j]-1][1]=j;
			}
		}
	}
	if(a!=-1){
		k=1;
		for(i=a;i<n;i++,k++){
			if(t[1][i]!=k)a=-1;
		}
		for(i=0;i<a;i++,k++){
			if(t[1][i]>0 && t[1][i]<=k)a=-1;
		}
	}
	if(a!=-1){
		cout<<a<<endl;
		return 0;
	}
	b=n;
	for(i=0;i<n;i++){
		if(p[i][0]==0)continue;
		a=p[i][1]+n-i+1;
		b=max(a,b);
	}
	cout<<b<<endl;
}