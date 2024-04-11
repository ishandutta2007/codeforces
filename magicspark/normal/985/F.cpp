#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=23333;
char buf[200005];
string read(){
	scanf("%s",buf);
	return buf;
}
int n,m;
string s;
ll hsh[200005][26];
ll pw[200005];
const int mod=1e9+7;
int get_hash(int id,int l,int len){
	return ((ll)hsh[l+len-1][id]-(ll)hsh[l-1][id]*pw[len]%mod+mod)%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	s=" "+read();pw[0]=1;
	for(int i=1;i<=200000;i++)pw[i]=(ll)pw[i-1]*base%mod;
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)hsh[i][j]=(ll)((ll)hsh[i-1][j]*base%mod+(s[i]=='a'+j))%mod;
	}
	while(m--){
		int a,b,len;scanf("%d%d%d",&a,&b,&len);
		vector<int>A,B;
		for(int i=0;i<26;i++){
			A.push_back(get_hash(i,a,len));
			B.push_back(get_hash(i,b,len));
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		if(A==B){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}