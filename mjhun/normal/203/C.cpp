#include <algorithm>
#include <iostream>
using namespace std;

struct client{
	int id;
	int cost;
};

client m[100005];

bool comp(client p, client q){
	return p.cost<q.cost;
}

int main(){
	int a,b,n,d,x,y,i,k;
	long long int s=0;
	cin>>n>>d>>a>>b;
	for(i=1;i<=n;++i){
		cin>>x>>y;
		m[i].id=i;
		m[i].cost=a*x+b*y;
	}
	sort(m+1,m+n+1,comp);
	for(i=1;i<=n&&s<=d;++i)
		s+=m[i].cost;
	if(s>d)
		i-=2;
	else
		i=n;
	cout<<i<<endl;
	for(k=1;k<=i;++k)
		cout<<m[k].id<<' ';
	cout<<endl;
	return 0;
}