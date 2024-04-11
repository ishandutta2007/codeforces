#include<bits/stdc++.h>
#define int long long
#define C(n,m) ((0>(m)||(m)>(n))?0:(ycl1[(m)]*ycl1[(n)-(m)]%mod*ycl2[(n)]%mod))
#define mod 998244353
using namespace std;
int ycl1[1000001],ycl2[1000001],ycl3[1000001],a[1000001],b[1000001];
string c;
void ycl()
{
	ycl1[0]=ycl2[0]=1;
	for(int x=1;x<=1000000;x++)
	ycl3[x]=(x==1)?1:(mod-mod/x)*ycl3[mod%x]%mod,ycl1[x]=ycl1[x-1]*ycl3[x]%mod,ycl2[x]=ycl2[x-1]*x%mod;
}
signed main()
{
	ycl();
	cin>>c;
	c=' '+c;
	int Left_brackets=0,Left_question_mark=0,Right_brackets=0,Right_question_mark=0;
	for(int x=1;c[x];x++)
	Right_brackets+=c[x]==')',Right_question_mark+=c[x]=='?';
	int ans=0;
	for(int x=1;c[x+1];x++)
	Left_brackets+=c[x]=='(',Left_question_mark+=c[x]=='?',Right_brackets-=c[x]==')',Right_question_mark-=c[x]=='?',ans=(ans+Left_question_mark*C(Left_question_mark+Right_question_mark-1,Left_brackets+Left_question_mark-Right_brackets)+Left_brackets*C(Left_question_mark+Right_question_mark,Left_brackets+Left_question_mark-Right_brackets))%mod;
	cout<<ans<<endl;
}