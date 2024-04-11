#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200002;
vector<int>x[N];
priority_queue<int>Q;
//priority_queue<int,vector<int>,greater<int> >Q2;
struct p{
	int id,a,t;
}f[N];
int n,m,T,i,j,a[N],t[N],u,v,q[N];
bool cmp(p u,p v){
	return u.t<v.t;
}
long long S;
int main(){
	scanf("%d%d",&n,&T);
	for(i=1;i<=n;i++){
		scanf("%d%d",a+i,t+i);
		x[a[i]].push_back(t[i]);
	}
	for(i=n;i;i--){
		for(j=0;j<x[i].size();j++)
			Q.push(x[i][j]),S+=x[i][j];
		while(Q.size()>i||S>T)
			S-=Q.top(),Q.pop();
		if(Q.size()>u)
			u=Q.size(),v=i;
	}
	printf("%d\n%d\n",u,u);
	m=0;
	for(i=1;i<=n;i++)
		if(a[i]>=v)
			f[++m]=(p){i,a[i],t[i]};
	sort(f+1,f+m+1,cmp);	
	m=0;	
	for(i=1;i<=u;i++)
		q[++m]=f[i].id;
	sort(q+1,q+u+1);
	for(i=1;i<=u;i++)
		printf("%d ",q[i]);
	//while(1);
}