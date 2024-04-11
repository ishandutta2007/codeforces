#include<bits/stdc++.h>
using namespace std;
int inf=1e9+1;
int n,m;
int r,c;
int x,y;
char s[4000];
int mat[4000][4000];
vector<pair<int,int> > a;
void bfs()
{
	a.push_back(make_pair(r,c));
	int ind=0;
	r=0;
	c=0;
	while(ind<a.size()) {
		r=a[ind].first;
		c=a[ind].second;
		if(r>0 && mat[r][c]<mat[r-1][c]) {
			mat[r-1][c]=mat[r][c];
			a.push_back(make_pair(r-1,c));
		}
		if(r<n-1 && mat[r][c]<mat[r+1][c]) {
			mat[r+1][c]=mat[r][c];
			a.push_back(make_pair(r+1,c));
		}
		if(c>0 && mat[r][c]+1<mat[r][c-1]) {
			mat[r][c-1]=mat[r][c]+1;
			a.push_back(make_pair(r,c-1));
		}
		if(c<m-1 && mat[r][c]<mat[r][c+1]) {
			mat[r][c+1]=mat[r][c];
			a.push_back(make_pair(r,c+1));
		}
		ind++;
	}
}
int main() {
	scanf("%d %d",&n,&m);
	scanf("%d %d",&r,&c);
	scanf("%d %d",&x,&y);
	r--;
	c--;
	for(int i=0;i<n;i++) {
		scanf("%s",s);
		for(int j=0;j<m;j++) {
			if(s[j]=='*') mat[i][j]=-1;
			else mat[i][j]=inf;
		}
	}
	mat[r][c]=0;
	int nc=c,xt,yt;
	int res=0;
	bfs();
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(mat[i][j]!=-1) {
				xt=mat[i][j];
				yt=xt+(j-nc);
				//cout<<"("<<xt<<","<<yt<<")"<<" ";
				if(xt<=x && yt<=y) res++;
			}
		}
		//cout<<endl;
	}
	printf("%d",res);
	return 0;
}