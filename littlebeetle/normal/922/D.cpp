#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100002;
struct p{
	int x,y,id;
	bool operator<(const p &k)const{
		return 1ll*k.x*y<1ll*k.y*x;
	}
}a[N];
int n,i,j;
long long p,q;
string s[N],S;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		cin>>s[i];
		for(j=0;j<s[i].size();j++){
			if(s[i][j]=='s')
				a[i].x++;
			else
				a[i].y++;
		}
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		S+=s[a[i].id];
	for(i=0;i<S.size();i++)
		if(S[i]=='s')
			p++;
		else
			q+=p;
	printf("%I64d",q);
}