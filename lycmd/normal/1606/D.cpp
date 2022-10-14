#include<bits/stdc++.h>
using namespace std;
int t,n,m;
vector<vector<int> >a,ln,lx,rn,rx;
vector<int>p;
set<pair<int,int> >lb,lr,rb,rr;
void init(vector<vector<int> >&a,int n,int m){
	a.resize(n+1);
	for(int i=0;i<=n;i++)
		a[i].resize(m+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		init(a,n,m),init(ln,n,m),init(lx,n,m);
		init(rn,n,m),init(rx,n,m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
			ln[i][1]=lx[i][1]=a[i][1],rn[i][m]=rx[i][m]=a[i][m];
		for(int i=1;i<=n;i++)
			for(int j=2;j<=m;j++)
				ln[i][j]=min(ln[i][j-1],a[i][j]),
				lx[i][j]=max(lx[i][j-1],a[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=m-1;j;j--)
				rn[i][j]=min(rn[i][j+1],a[i][j]),
				rx[i][j]=max(rx[i][j+1],a[i][j]);
		int flg=0;
		for(int j=1;j<m;j++){
			lb.clear(),lr.clear(),rb.clear(),rr.clear(),p.clear();
			for(int i=1;i<=n;i++)
				lb.insert({lx[i][j],i}),rb.insert({rn[i][j+1],i}),
				p.push_back(i);
			sort(p.begin(),p.end(),[&](int a,int b){
				return ln[a][j]>ln[b][j];
			});
			for(int i=1;i<n;i++){
				int x=p[i-1];
				lb.erase({lx[x][j],x}),rb.erase({rn[x][j+1],x});
				lr.insert({ln[x][j],x}),rr.insert({rx[x][j+1],x});
				if((lb.rbegin()->first)<(lr.begin()->first)&&
				   (rr.rbegin()->first)<(rb.begin()->first)){
					cout<<"YES\n";
					for(int i=1;i<=n;i++)
						cout<<(lb.count({lx[i][j],i})?"B":"R");
					cout<<" "<<j<<"\n",flg=1;
					goto finish;
				}
			}
		}
finish:	if(!flg)cout<<"NO\n";
	}
}