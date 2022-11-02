#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int k;
int sum[222222];
string a,b; 
void divide(){
	for(int i=0;i<=k;i++){
		if(sum[i]&1){
			sum[i]--;sum[i+1]+=26;
			sum[i]/=2;
		}else sum[i]/=2;
	}
}
int main(){
	cin>>k;
	cin>>a>>b;
	for(int i=1;i<=k;i++)sum[i]=a[i-1]+b[i-1]-'a'-'a';
	for(int i=k;i>0;i--)while(sum[i]>=26)sum[i-1]++,sum[i]-=26;
	divide();
	for(int i=1;i<=k;i++)putchar('a'+sum[i]);
	return 0;
}