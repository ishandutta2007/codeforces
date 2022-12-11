#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
int a[5];
void no(){cout<<"Tidak ";}
void yes(){cout<<"Ya ";}
void work()
{
	int cnt=0;
	for(int i=1;i<=4;i++) a[i]=read();
	for(int i=1;i<=4;i++) if(a[i]) cnt++;
	int sum=0;
	for(int i=1;i<=2;i++) sum+=a[i];
	bool A=0,B=0;
	if(a[1]||a[4]) A=1;
	if(a[2]||a[3]) B=1;
	if(sum&1)
	{
		if(A&&B) yes(),yes(),no(),no();
		else if(A) yes(),no(),no(),no();
		else no(),yes(),no(),no();
	}
	else
	{
		if(A&&B) no(),no(),yes(),yes();
		else if(A) no(),no(),no(),yes();
		else no(),no(),yes(),no();
	}
	cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}