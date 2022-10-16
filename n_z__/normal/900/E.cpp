#include<bits/stdc++.h>
#define w1(x,y) b[x][y]=(s[y]=='a'+!x||s[y]=='?')?b[!x][y-1]+1:0
#define x first
#define y second
#define z x-m
using namespace std;
int a[100001],b[2][100001];
pair<int,int>c[100001];
int main(){
	int n,m;
	string s;
	cin>>n>>s>>m; 
	s=' '+s;
	for(int x=1;x<=n;x++)
	a[x]=a[x-1]+(s[x]=='?'),w1(1,x),w1(0,x),c[x]=max((b[m%2][x]>=m)?make_pair(c[z].x+1,c[z].y-a[x]+a[z]):c[0],c[x-1]);
	cout<<-c[n].y;
}