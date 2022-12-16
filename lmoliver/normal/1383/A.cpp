#include<bits/stdc++.h>
using namespace std;

const int N=1001001;
int n;
char a[N],b[N];

const int X=26;
bool m[X][X];
struct UFS{
	int fa[X];
	UFS(){
		memset(fa,-1,sizeof(fa));
	}
	int find(int a){
		return fa[a]<0?a:(fa[a]=find(fa[a]));
	}
	void mg(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return;
		fa[a]+=fa[b];
		fa[b]=a;
	}
};
int solve(){
	UFS u;
	memset(m,false,sizeof(m));
	for(int i=0;i<n;i++){
		if(b[i]<a[i]){
			return -1;
		}
		if(b[i]>a[i]){
			u.mg(a[i]-'a',b[i]-'a');
		}
	}
	int ans=0;
	for(int i=0;i<X;i++){
		if(u.find(i)==i)ans+=(-u.fa[i])-1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>a;
		cin>>b;
		cout<<solve()<<endl;
	}
	return 0;
}