#include<bits/stdc++.h>
using namespace std;
int const N=1000010,B=22;
int t,n,m,a[N],p[B][N],v[N];
char c;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		int s=n*m,c1=0,c2=0;
		for(int i=0;i<s;i++)
			cin>>c,a[i]=c^49,v[i]=0;
		for(int i=0;i<s;i++)
			switch(cin>>c,c){
				case'L':p[0][i]=i-1;break;
				case'R':p[0][i]=i+1;break;
				case'U':p[0][i]=i-m;break;
				case'D':p[0][i]=i+m;break;
			}
		for(int i=1;i<B;i++)
			for(int j=0;j<s;j++)
				p[i][j]=p[i-1][p[i-1][j]];
		for(int i=0;i<s;i++)
			v[p[B-1][i]]|=2|a[i];
		for(int i=0;i<s;i++)
			c1+=!!v[i],c2+=v[i]&1;
		cout<<c1<<" "<<c2<<"\n";
	}
}