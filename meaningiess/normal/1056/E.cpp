#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define Ull unsigned long long
#define ll long long
#define N 1000+1000000
#define mod 998244353
using namespace std;
Ull h1[N],h2[N],pw1[N],pw2[N];
char a[N],b[N];int l1,l2,c0,c1;
Ull gt2(int x,int y)
{
    return (h2[y]-(h2[x-1]*pw2[y-x+1]%mod)+mod)%mod;
}
Ull gt1(int x,int y)
{
    return h1[y]-h1[x-1]*pw1[y-x+1];
}
const int MAX=2000;
int len[MAX],r[MAX],str[MAX];
int init(int n)
{
    for(int i=1,j=0;i<=2*n;j++,i+=2)
    {
        r[i]=-1;
        r[i+1]=str[j];
    }
    r[0]=-2;
    r[2*n+1]=-1;
    r[2*n+2]=-3;
    r[2*n+3]=-4;
    return 2*n+1;
}
int sol(int L)
{
    int R=l2-c0*L; if (R%c1!=0) return 0;R/=c1;
    Ull ln1=gt1(1,L),ln2=gt2(1,L); int i,we;
    for (i=1,we=1;i<=l2;i+=L,we++) if (a[we]=='1') break;
    Ull t11=gt1(i,i+R-1),t12=gt2(i,i+R-1);
	if (ln1==t11 && ln2==t12) return 0;
    for (i=1,we=1;i<=l2;we++)
    	if (a[we]=='1')
		{
    		Ull t1=gt1(i,i+R-1),t2=gt2(i,i+R-1);
    		if (t1!=t11||t2!=t12) return 0;i+=R;
    	}
    	else
		{
    		Ull t1=gt1(i,i+L-1),t2=gt2(i,i+L-1);
    		if (t1!=ln1||t2!=ln2) return 0;i+=L;
    	}
    return 1;
}
void mana(int n)
{
    int mx=0,p=0,i;
    for (i=1;i<=n;i++)
    {
        if(mx>i)len[i]=min(mx-i,len[2*p-i]);
        else len[i]=1;
        while(r[i-len[i]]==r[i+len[i]])len[i]++;
        if(len[i]+i>mx)mx=len[i]+i,p=i;
    }
}
int main()
{
    int ans=0,i;scanf("%s%s",a+1,b+1);
	pw1[0]=pw2[0]=1;l1=strlen(a+1),l2=strlen(b+1);
	if (a[1]=='1') for (i=1;i<=l1;i++) a[i]=(a[i]=='1')?'0':'1';
	for (i=1;i<=l1;i++) c1+=(a[i]=='1')?1:0;
	for (i=1;i<=l1;i++) c0+=(a[i]=='0')?1:0;
	for (i=1;i<=l2;i++) h2[i]=h2[i-1]*137+(b[i]-'a'+1),h2[i]%=mod;
	for (i=1;i<=l2;i++) h1[i]=h1[i-1]*233+(b[i]-'a'+1);
	for (i=1;i<=l2;i++) pw2[i]=pw2[i-1]*137,pw2[i]%=mod;
	for (i=1;i<=l2;i++) pw1[i]=pw1[i-1]*233;
    for (i=1;i<=l2;i++){if (l2-c0*i<c1) break;ans+=sol(i);}
    cout<<ans;
}