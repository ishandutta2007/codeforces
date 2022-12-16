#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#ifdef DEBUG
const int n=6;
struct P{int x,y;};
const P points[n]={
	{-2,1},
	{3,-1},
	{-2,-1},
	{1,-2},
	{0,3},
	{2,2},
};
P operator-(P a,P b){
	return {a.x-b.x,a.y-b.y};
}
LL cross(P a,P b){
	return (LL)a.x*b.y-(LL)a.y*b.x;
}
LL q(int t,int i,int j,int k){
	cerr<<(t==1?"area":"test")<<" "<<i<<" "<<j<<" "<<k<<endl;
	P a=points[j-1]-points[i-1];
	P b=points[k-1]-points[i-1];
	LL c=cross(a,b);
	LL r=t==1?abs(c):c>0?1:-1;
	cerr<<"< "<<r<<endl;
	return r;
}
#else
LL q(int t,int i,int j,int k){
	cout<<t<<" "<<i<<" "<<j<<" "<<k<<endl<<flush;
	LL ans;
	cin>>ans;
	return ans;
}
#endif

const int N=5050;
LL a[N];
int l[N];
vector<int> id[2];
int main(){
	ios::sync_with_stdio(false);
#ifndef DEBUG
	int n;
	cin>>n;
#endif
	int w=2;
	for(int i=3;i<=n;i++){
		if(q(2,1,w,i)==-1){
			w=i;
		}
	}
	int mx=-1;
	for(int i=2;i<=n;i++){
		if(i==w)continue;
		a[i]=q(1,1,w,i);
		if(mx==-1||a[i]>a[mx])mx=i;
	}
	for(int i=2;i<=n;i++){
		if(i==w||i==mx)continue;
		id[q(2,1,mx,i)==-1?0:1].push_back(i);
	}
	sort(id[0].begin(),id[0].end(),[&](int x,int y){
		return a[x]<a[y];
	});
	sort(id[1].begin(),id[1].end(),[&](int x,int y){
		return a[x]<a[y];
	});
	reverse(id[1].begin(),id[1].end());
	cout<<"0 1 "<<w;
	for(int i:id[0])cout<<" "<<i;
	cout<<" "<<mx;
	for(int i:id[1])cout<<" "<<i;
	cout<<endl<<flush;
	return 0;
}