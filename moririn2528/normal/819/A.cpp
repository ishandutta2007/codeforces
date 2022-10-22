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

int num[10][100];
int used[100];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m>>a>>b;
	if(b-a>3*(n+m)){
		c=n+max(n-m,1);
		cout<<c<<endl;
		return 0;
	}
	for(i=0;i<n+m;i++){
		if(i<n)num[0][i]=i;
		else num[0][i]=n-1;
	}
	for(i=1;i<5;i++){
		memset(used,false,sizeof(used));
		for(j=m;j<n+m;j++){
			used[num[i-1][j]]=true;
		}
		k=0;
		for(j=0;j<n;j++){
			while(used[k])k++;
			num[i][j]=k;
			used[k]=true;
		}
		for(j=0;j<m;j++){
			num[i][n+j]=num[i][n-1];
		}
	}
	a--,b--;
	c=a/(n+m)*(n+m);
	a-=c,b-=c;
	if(a>=n && n>m){
		for(i=0;i<m;i++){
			num[0][n+i]=num[0][m];
		}
	}
	memset(used,false,sizeof(used));
	int s=0;
	for(i=a;i<=b;i++){
		c=num[i/(n+m)][i%(n+m)];
		if(used[c])continue;
		used[c]=true;
		s++;
	}
	cout<<s<<endl;
}