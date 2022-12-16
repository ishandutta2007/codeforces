#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)

const int N=100100;
int a[N],b[N];
int pos[N];
bool vis[N];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	F(i,1,n){
		cin>>a[i];
	}
	F(i,1,n){
		cin>>b[i];
		pos[b[i]]=i;
	}
	vis[0]=true;
	int ans=0;
	F(i,1,n){
		int x=pos[a[i]];
		if(!vis[x]){
			vis[x]=true;
			for(int j=x-1;!vis[j];j--){
				vis[j]=true;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}