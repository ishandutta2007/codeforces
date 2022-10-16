#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

int n,m;
int res;
int fa[N];
int a[N],id[N];
int w[N];

void ask(){
	cout<<"? ";
	for(int i=1;i<=m;i++)
		cout<<a[i];cout<<endl;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		a[i]=1;
		ask();
		id[i]=i;
		cin>>w[i];
		a[i]=0;
	}
	sort(id+1,id+1+m,[&](int x,int y){return w[x]<w[y];});
	int pre=0;
	for(int i=1;i<=m;i++){
		a[id[i]]=1;
		ask();int nw;cin>>nw;
		if(pre+w[id[i]]==nw){
			pre=nw;
		}else{
			a[id[i]]=0;
		}
	}
	cout<<"! "<<pre<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}