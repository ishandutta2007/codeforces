#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e3+10;
int n;
inline void print(int k){
	cout<<"! "<<k<<endl;
	cout.flush();
	exit(0);
}
inline int query(int l,int r){
	int tmp;
	cout<<"? "<<l<<" "<<r<<endl;
	cout.flush();
	cin>>tmp;
	return tmp;
}
void dfs(int l,int r,int sec){
	if(l+1>=r)print(l==sec?r:l);
	int mid=l+r>>1,tmp;
	if(sec<=mid){
		tmp=query(l,mid);
		if(tmp==sec)dfs(l,mid,sec);
		else dfs(mid,r,sec==mid?sec:query(mid,r));
	}
	else{
		tmp=query(mid,r);
		if(tmp==sec)dfs(mid,r,sec);
		else dfs(l,mid,query(l,mid));
	}
}
int main(){
	cin>>n;
	dfs(1,n,query(1,n));
	return 0;
}