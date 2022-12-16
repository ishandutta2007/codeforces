#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1001001;
int a[N];
bool e(int c0,int c1){
	return c0%2==1||c1%4==1;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=30;i>=0;i--){
			int c[2]={0};
			for(int j=1;j<=n;j++)c[(a[j]>>i)&1]++;
			if(c[1]%2==1){
				puts(e(c[0],c[1])?"WIN":"LOSE");
				goto no;
			}
		}
		puts("DRAW");
		no:;
	}
	return 0;
}