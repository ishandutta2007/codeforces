#include<bits/stdc++.h>
using namespace std;
int n,k;
struct node{
	static int const N=12;
	int cnt,mx[N],mn[N];
	node():cnt(0){memset(mx,0,sizeof mx),memset(mn,0x3f,sizeof mn);}
	int operator<(const node&rhs)const{
		for(int i=1;i<=k;i++)
			if(mx[i]>rhs.mn[i])
				return 0;
		return 1;
	}
	node operator+(const node&rhs)const{
		node res;
		res.cnt=cnt+rhs.cnt;
		for(int i=1;i<=k;i++)
			res.mx[i]=max(mx[i],rhs.mx[i]),
			res.mn[i]=min(mn[i],rhs.mn[i]);
		return res;
	}
};
node a;
set<node>s;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		a.cnt=1;
		for(int i=1;i<=k;i++)
			cin>>a.mx[i],a.mn[i]=a.mx[i];
		while(s.find(a)!=s.end()){
			node t=*s.find(a);
			a=a+t,s.erase(s.find(a));
		}
		s.insert(a);
		cout<<(*s.rbegin()).cnt<<"\n";
	}
}