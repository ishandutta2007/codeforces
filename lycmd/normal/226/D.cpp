#include<bits/stdc++.h>
using namespace std;
int const N=105;
int n,m,a[N][N],s1[N],s2[N],v1[N],v2[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],s1[i]+=a[i][j],s2[j]+=a[i][j];
	for(int flg=1;flg;){
		flg=0;
		for(int i=1;i<=n;i++)
			if(s1[i]<0){
				flg=1,s1[i]*=-1,v1[i]^=1;
				for(int j=1;j<=m;j++)
					s2[j]-=a[i][j],a[i][j]*=-1,s2[j]+=a[i][j];
			}
		for(int j=1;j<=m;j++)
			if(s2[j]<0){
				flg=1,s2[j]*=-1,v2[j]^=1;
				for(int i=1;i<=n;i++)
					s1[i]-=a[i][j],a[i][j]*=-1,s1[i]+=a[i][j];
			}
	}
	int c1=0,c2=0;
	for(int i=1;i<=n;i++)
		c1+=v1[i];
	for(int j=1;j<=m;j++)
		c2+=v2[j];
	cout<<c1;
	for(int i=1;i<=n;i++)
		if(v1[i])cout<<" "<<i;
	cout<<"\n"<<c2;
	for(int j=1;j<=m;j++)
		if(v2[j])cout<<" "<<j;
}