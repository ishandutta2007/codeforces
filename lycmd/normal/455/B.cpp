#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,k,tot,tr[N][27];
string s;
void insert(const string&s){
	int p=0;
	for(char i:s){
		int&t=tr[p][i-97];
		p=t?t:t=++tot;
	}
}
int dfs(int x){
	int res=0,lf=1;
	for(int i=0;i<26;i++)
		if(tr[x][i])
			lf=0,res|=dfs(tr[x][i]);
	return lf?1:res^3;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>k;n--;)
		cin>>s,insert(s);
	int ans=dfs(0);
	cout<<(!ans||(ans==2&&k&1)?"First\n":"Second\n");
}