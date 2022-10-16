#include<bits/stdc++.h>
#define int long long
const int N=5005,mod=998244353;
using namespace std;

int f[N][N];

int jc[N],ij[N],iv[N]; 
int C(int n,int m){
	if(n==m)return 1; 
    if(n<m)return 0;
    return jc[n]*ij[m]%mod*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}

void solve(){
	init();
	int n,k;cin>>n>>k;
	string s;cin>>s;
	int m=count(s.begin(),s.end(),'1');
	if(m<k){
		cout<<1<<endl;return ;
	}
	vector<int> A; 
	A.push_back(0); 
	for(int i=0;i<n;i++)
		if(s[i]=='1')
			A.push_back(i+1);
	A.push_back(n+1);
	int ans=0;
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m&&j<i+k;j++){
			ans+=C(A[j+1]-A[i-1]-1,j-i+1);
			ans+=C(A[j]-A[i]-1,j-i-1);
			ans-=C(A[j]-A[i-1]-1,j-i);
			ans-=C(A[j+1]-A[i]-1,j-i);
		}
	cout<<(ans%mod+mod+1)%mod<<endl;
}

main(){
	init();
	int _T=1;//cin>>_T;
	while(_T--)solve();
}