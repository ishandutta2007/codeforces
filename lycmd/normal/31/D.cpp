#include<bits/stdc++.h>
#define ord(i,j) ((i)*n+(j))
using namespace std;
int const N=233,M=23333;
int n,m,k,f[M],a[N][N],b[N][N],sz[M];
vector<int>ans;
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	while(k--){
		int ax,ay,bx,by;
		cin>>ax>>ay>>bx>>by;
		if(ax>bx)swap(ax,bx);
		if(ay>by)swap(ay,by);
		if(ax==bx){
			for(int y=ay;y<by;y++)
				a[y][ax]=1;
		}else{
			for(int x=ax;x<bx;x++)
				b[ay][x]=1;
		}
	}
	for(int i=0;i<=ord(m-1,n-1);i++)
		f[i]=i;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			if(!a[i][j]&&j)
				merge(ord(i,j-1),ord(i,j));
			if(!b[i][j]&&i)
				merge(ord(i-1,j),ord(i,j));
		}
	for(int i=0;i<=ord(m-1,n-1);i++)
		sz[find(i)]++;
	for(int i=0;i<=ord(m-1,n-1);i++)
		if(i==f[i])
			ans.push_back(sz[i]);
	sort(ans.begin(),ans.end());
	for(int x:ans)cout<<x<<" ";
	cout<<"\n";
}