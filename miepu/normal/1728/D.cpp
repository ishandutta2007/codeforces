#include<bits/stdc++.h>
#define int long long
const int N=2005;
using namespace std;

int A[N][N];
int n;
string s;
string Ans[4]={"","Alice","Draw","Bob"};

int a(int l,int r);
int b(int k,int l,int r);

int a(int l,int r){
	if(A[l][r])return A[l][r];
	if(l>r)return 2;
	return A[l][r]=min(b(s[l]-'a',l+1,r),b(s[r]-'a',l,r-1));
}
int b(int k,int l,int r){
	int res=1;
	res=max(res,a(l+1,r));
	res=max(res,a(l,r-1));
	if(res!=2)
		return res;
	if(s[l]-'a'<k&&a(l+1,r)==2)return 3;
	if(s[r]-'a'<k&&a(l,r-1)==2)return 3;
	if(s[l]-'a'==k&&a(l+1,r)==2)return 2;
	if(s[r]-'a'==k&&a(l,r-1)==2)return 2;
	return 1;
}

void solve(){
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		A[i][j]=0;
	cout<<Ans[a(0,n-1)]<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}