#include<bits/stdc++.h>
using namespace std;
struct bign
{
    int len;
    int num[200005];
    bool flag;
    bign(){len=1;flag=0;memset(num,0,sizeof(num));}
};
bool operator < (bign a,bign b){
    if(a.len<b.len)return 1;
    if(a.len>b.len)return 0;
    for(int i=a.len;i>=1;i--)if(a.num[i]!=b.num[i])return a.num[i]<b.num[i];
    return 1;
}
bool operator == (bign a,bign b){
    if(a.len!=b.len)return 0;
    for(int i=1;i<=a.len;i++)if(a.num[i]!=b.num[i])return 0;
    return 1;
}
bign operator + (bign a,bign b){
    bign ans;
    int i=1,x=0;
    while(i<=a.len || i<=b.len){
        ans.num[i]+=x;ans.num[i]+=(a.num[i]+b.num[i]);
        x=ans.num[i]/10;ans.num[i]%=10;  i++;
    }
    ans.num[i]=x;
    if(!ans.num[i])i--;
    ans.len=i;
    return ans;
}
char s[100010];
bign get(int a,int b)
{
    bign ans;
    int l=b-a+1;
    ans.len=l;
    for(int i=a;i<=b;i++)ans.num[l+a-i]=s[i]-48;
    return ans;
}
void out(bign x)
{
    if(x.flag)
    {
        cout<<"-";
        for(int i=x.len-1;i>=1;i--)
        {
            cout<<x.num[i];
        }
    }
    else
    for(int i=x.len;i>=1;i--)
    {
        cout<<x.num[i];
    }cout<<endl;
}
int main()
{
    int cnt,l,i,e;cin>>l;cin>>s;e=l/2;bign ans;ans.len=100001;cnt=3;
	for (i=e-1;i && cnt;i--) if (s[i]!='0') {bign t=get(0,i-1)+get(i,l-1);if (t<ans)ans=t;cnt--;}cnt=3;
	for (i=e;i<l && cnt;i++) if (s[i]!='0')
	{
		bign a=get(i,l-1),b=get(0,i-1),tp=a+b;
		if (tp<ans)ans=tp;
		cnt--;
	}
	out(ans);
}