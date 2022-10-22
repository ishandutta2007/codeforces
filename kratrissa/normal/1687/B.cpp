#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m,a[N],id[N],ans,res;string s;
bool cmp(int x,int y){return a[x]<a[y];}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		s="? ";
		for(int j=1;j<i;j++)s+='0';
		s+='1';
		for(int j=i+1;j<=m;j++)s+='0';
		cout<<s<<endl;cin>>a[i];
	}
	for(int i=1;i<=m;i++)id[i]=i;
	sort(id+1,id+m+1,cmp);
	s="";
	for(int i=1;i<=m;i++)s+='0';
	for(int i=1;i<=m;i++){
		s[id[i]-1]='1';
		cout<<"? "<<s<<endl,cin>>res;
		if(res==ans+a[id[i]]){ans=res;continue;}
		s[id[i]-1]='0';
	}
	cout<<"! "<<ans<<endl;
	return 0;
}