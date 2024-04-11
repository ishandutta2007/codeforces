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
typedef tuple<int,int,int> T;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}

LL t[1000005];
LL tt[1000005];
LL q[1000005];

priority_queue<P> q1;

int main(){
	int n,m;
	int p;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>p;
		a=0;
		for(j=0;j<p;j++){
			cin>>q[j];
			if(q[a]<q[j])a=j;
		}
		if(p<m/2){
			if(q[a]<0)continue;
			tt[a]+=q[a],tt[m-p+1+a]-=q[a];
			b=-INF;
			for(j=0;j<a;j++){
				if(b<q[j])b=q[j];
				if(j<m-p && b<0)continue;
				t[j]+=b;
			}
			b=-INF;
			for(j=p-1,k=m-1;j>a;j--,k--){
				if(b<q[j])b=q[j];
				if(k>=p && b<0)continue;
				t[k]+=b;
			}
		}else{
			while(!q1.empty())q1.pop();
			q1.push(make_pair(0,-1));
			a=m-p;
			for(j=0;j<m;j++){
				if(j<p)q1.push(make_pair(q[j],j));
				if(j==p)q1.push(make_pair(0,p));
				while(q1.top().second<j-a)q1.pop();
				t[j]+=q1.top().first;
			}
		}
	}
	for(i=0;i<m;i++){
		tt[i+1]+=tt[i];
		t[i]+=tt[i];
	}
	array_show(t,m);
}