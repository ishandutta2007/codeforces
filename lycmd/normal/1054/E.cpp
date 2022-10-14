#include<bits/stdc++.h>
using namespace std;
int const N=305;
int n,m,cnt[N][N];
string a[N][N],b[N][N];
vector<array<int,4> >seq1,seq2;
void add(int sx,int sy,int tx,int ty,vector<array<int,4> >&seq){
	seq.push_back({sx,sy,tx,ty});
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			reverse(a[i][j].begin(),a[i][j].end());
			for(char c:a[i][j]){
				int x=1+c%2,y=i^x?j:1+(j==1);
				add(i,j,x,y,seq1),cnt[x][y]++;
			}
		}
	for(int i=1;i<=2;i++)
		for(int j=2;j<=m;cnt[i][j++]=0)
			while(cnt[i][j]--)
				add(i,j,i,1,seq1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(char c:b[i][j]){
				int x=1+c%2,y=i^x?j:1+(j==1);
				add(x,y,i,j,seq2),cnt[x][y]++;
			}
	for(int i=1;i<=2;i++)
		for(int j=2;j<=m;cnt[i][j++]=0)
			while(cnt[i][j]--)
				add(i,1,i,j,seq2);
	reverse(seq2.begin(),seq2.end());
	cout<<seq1.size()+seq2.size()<<"\n";
	for(auto i:seq1){
		for(int j=0;j<4;j++)cout<<i[j]<<" ";
		cout<<"\n";
	}
	for(auto i:seq2){
		for(int j=0;j<4;j++)cout<<i[j]<<" ";
		cout<<"\n";
	}
}