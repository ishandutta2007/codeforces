#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
struct d{
	int x,y,nam;
	bool operator < (const d xx) const{return x<xx.x;}
}qwq[N];
priority_queue<long long int> ovo;
long long int ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&qwq[i].x,&qwq[i].y);
		qwq[i].nam=i;
	}
	sort(qwq+1,qwq+n+1);
	int x1=0;
	for(int i=1;i<=n;i++){if(qwq[i].nam==1)x1=i;}
	/*
	max(y,x_j-x_i)
	x_j<=y+x_i
	*/
	for(int i=1;i<=x1;i++){
		ovo.push(qwq[i].x+qwq[i].y);
	}
	for(int i=x1+1;i<=n;i++){
		if(ovo.top()>qwq[i].x){
			ovo.push(qwq[i].x+qwq[i].y);
		}
		else{
			ans=ans+qwq[i].x-ovo.top();
			ovo.pop();
			ovo.push(qwq[i].x+qwq[i].y);
		}
	}
	for(int i=1;i<=n;i++){
		ans+=qwq[i].y;
	}
	
	while(!ovo.empty())ovo.pop();
	ovo.push(qwq[1].x+qwq[1].y);
	for(int i=2;i<=x1;i++){
		if(ovo.top()>qwq[i].x){
			ovo.push(qwq[i].x+qwq[i].y);
		}
		else{
			ans=ans+qwq[i].x-ovo.top();
			ovo.pop();
			ovo.push(qwq[i].x+qwq[i].y);
		}
	}
	printf("%lld\n",ans);
	return 0;
}