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
#include<set>
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

int t[2200][2200];
bool bt[2200][2200];
string st[2200];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	memset(t,-1,sizeof(t));
	t[0][0]=m;
	for(i=0;i<n;i++){
		cin>>st[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a=t[i][j];
			if(st[i][j]!='a')a--;
			t[i+1][j]=max(t[i+1][j],a);
			t[i][j+1]=max(t[i][j+1],a);
		}
	}
	bt[0][0]=true;
	string ss;
	for(i=0;i<2*n-1;i++){
		a=100;
		for(j=max(0,i-n+1);j<n && i-j>=0;j++){
			if(!bt[j][i-j])continue;
			if(t[j][i-j]>0)a=0;
			else a=min(a,(int)st[j][i-j]-(int)'a');
		}
		for(j=max(0,i-n+1);j<n && i-j>=0;j++){
			if(!bt[j][i-j])continue;
			if(t[j][i-j]>0 || a==(int)st[j][i-j]-(int)'a'){
				bt[j][i-j+1]=true,bt[j+1][i-j]=true;
			}
		}
		ss.push_back('a'+a);
	}
	cout<<ss<<endl;
}