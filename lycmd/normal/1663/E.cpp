#include<bits/stdc++.h>
using namespace std;
int const N=233,dx[]={0,1,1},dy[]={1,0,1};
int n;
char a[N][N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int p=0;p<8;p++){
				string s="";
				int tx=i,ty=j;
				for(int t=7;t--;tx+=dx[p],ty+=dy[p]){
					if(tx<1||ty<1||tx>n||ty>n)
						break; 
					s+=a[tx][ty];
				}
				if(s=="theseus")
					cout<<"YES\n",exit(0);
			}
	cout<<"NO\n";
}