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
typedef pair<LL,LL> P;
typedef pair<LL,int> LP;
const LL INF=(LL)1<<41;
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

LL t[220000][3];
priority_queue<P,vector<P>,greater<P>> q1;
int n,m;

bool check(LL p){
	int i,j,k;
	LL a,b,c;

	for(i=0;i<m;i++){
		if(q1.empty())break;
		a=q1.top().first,b=q1.top().second,q1.pop();
		if(a<i)return false;
		t[b][2]+=p;
		if(t[b][2]<t[b][1]*(m-1))q1.push(make_pair(t[b][2]/t[b][1],b));
	}
	for(i=0;i<n;i++){
		if(t[i][2]<t[i][1]*(m-1))return false;
	}
	return true;
}

int main(){
	int i,j,k;
	LL a,b,c;
	cin>>n>>m;
	for(j=0;j<2;j++){
		for(i=0;i<n;i++){
			cin>>t[i][j];
		}
	}
	a=-1;
	for(i=0;i<n;i++){
		b=(m-1)*t[i][1]-t[i][0];
		if(b>0)a+=b;
	}
	a/=m;
	if(a==0)a=-1;
	LL z[3]={a,INF};
	while(z[1]-z[0]>1){
		z[2]=(z[0]+z[1])/2;
		for(i=0;i<n;i++){
			t[i][2]=t[i][0];
		}
		priority_queue<P,vector<P>,greater<P>> qtemp;
		swap(q1,qtemp);
		for(i=0;i<n;i++){
			q1.push(make_pair(t[i][0]/t[i][1],i));
		}
		if(check(z[2]))z[1]=z[2];
		else z[0]=z[2];
	}
	if(z[1]==INF)z[1]=-1;
	cout<<z[1]<<endl;
}