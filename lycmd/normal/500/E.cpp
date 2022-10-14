#include<bits/stdc++.h>
using namespace std;
int const N=233333,B=18;
int n,q,l[N],r[N],lg[N],mx[N],to[B][N],w[B][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i],r[i]+=l[i];
	to[0][n]=n+1;
	for(int i=n-1;i;i--){
		int p=i+1;
		while(p<=n&&r[i]>=l[p])
			r[i]=max(r[i],r[p]),p=to[0][p];
		to[0][i]=p,w[0][i]=l[p]-r[i];
	}
	for(int i=1;i<B;i++)
		for(int j=1;j<=n-(1<<i);j++)
			to[i][j]=to[i-1][to[i-1][j]],w[i][j]=w[i-1][j]+w[i-1][to[i-1][j]];
	for(cin>>q;q--;){
		int l,r,res=0;cin>>l>>r;
		for(int i=B-1;~i;i--)
			if(to[i][l]&&to[i][l]<=r)
				res+=w[i][l],l=to[i][l];
		cout<<res<<"\n";
	}
}