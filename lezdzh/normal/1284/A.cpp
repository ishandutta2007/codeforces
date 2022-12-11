#include<cstdio>
#include<iostream>
using namespace std;

string u[21],v[21];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		cin>>u[i];
	for(int i=0;i<m;i++)
		cin>>v[i];
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int o;
		scanf("%d",&o);
		o--;
		cout<<u[o%n]<<v[o%m]<<"\n";
	}
}