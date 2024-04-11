#include<bits/stdc++.h>
struct IO_Tp {
    IO_Tp &operator>>(int &res) {
        int f=1;
        char ch=getchar();
        while (!isdigit(ch)&&(ch)!='-') ch=getchar();
        if(ch=='-')f=-1,ch=getchar();
        res=0;
        while (isdigit(ch)) res = res * 10 + (ch - '0'),ch=getchar();
        res*=f;
        return *this;
    }
    #define int long long
    IO_Tp &operator>>(int &res) {
        int f=1;
        char ch=getchar();
        while (!isdigit(ch)&&(ch)!='-') ch=getchar();
        if(ch=='-')f=-1,ch=getchar();
        res=0;
        while (isdigit(ch)) res = res * 10 + (ch - '0'),ch=getchar();
        res*=f;
        return *this;
    }
    #undef int
    #define int double
    IO_Tp &operator>>(int &res) {
        int f=1;
        char ch=getchar();
        while (!isdigit(ch)&&(ch)!='-') ch=getchar();
        if(ch=='-')f=-1,ch=getchar();
        res=0;
        while (isdigit(ch)) res = res * 10 + (ch - '0'),ch=getchar();
        if(ch=='.'){
        	double x=0.1;
        while(isdigit(ch)) res = res+(ch-'0')*x,x*=0.1;
    	}
        res*=f;
        return *this;
    }
    #undef int
} IO;
#define cin IO
#define endl '\n'
#define int long long
using namespace std;
int rk[400000],sa[400000],lcp[400000][18],tot[2],vr[26],d[400000],w[400000][2];
pair<int,bool>a[400000];
vector<int>v1[400000];vector<pair<int,int>>v2[400000];
signed main(){
	int n,q;
	cin>>n>>q;
	string s;
	#undef cin
	cin>>s;
	#define cin IO
	s=' '+s;
	for(int x=1;x<=n;x++)
	vr[s[x]-'a']=1;
	for(int x=1;x<=25;x++)
	vr[x]+=vr[x-1];
	for(int x=1;x<=n;x++)
	rk[x]=vr[s[x]-'a'];
	for(int y=0;y<=17;y++){
		for(int x=1;x<=n;x++)
		v1[x].clear(),v2[x].clear();
		for(int x=1;x<=n;x++)
		v1[rk[x+(1<<y)]].push_back(x);
		for(int x=0;x<=n;x++)
		for(auto z:v1[x])
		v2[rk[z]].push_back({z,rk[z+(1<<y)]});
		int o=0;
		for(int x=0;x<=n;x++)
		{
			pair<int,int>ls={0,-1};
			for(auto z:v2[x]){
				if(z.second!=ls.second)o++;
				rk[z.first]=o;
				ls=z;
			}
		}
	}
	for(int x=1;x<=n;x++)
	sa[rk[x]]=x;
	for(int x=1;x<=n;x++)
	for(lcp[rk[x]][0]=max(lcp[rk[x-1]][0]-1,0ll);s[x+lcp[rk[x]][0]]==s[sa[rk[x]-1]+lcp[rk[x]][0]];)
	lcp[rk[x]][0]++;
	for(int y=1;y<=17;y++)
	for(int x=1;x<=n;x++)
	lcp[x][y]=min(lcp[x][y-1],lcp[x+(1<<(y-1))][y-1]);
	for(int o=1;o<=q;o++)
	{
		int ans=0,tot[2]={0,0};
		int k,l;
		cin>>k>>l; 
		for(int x=1;x<=k;x++)
		{
			int o;
			cin>>o;
			a[x]={rk[o],0};
		}
		for(int x=1;x<=l;x++)
		{
			int o;
			cin>>o;
			a[x+k]={rk[o],1};
		}
		sort(a+1,a+k+l+1);
		int t=0,lf=a[1].first;
		for(int x=2;x<=k+l;x++)
		{
			int o=0,al[2]={0,0};
			al[a[x-1].second]=1;
			if(a[x].first==lf)o=n-sa[a[x].first]+1;
			else
			for(int y=17;y>=0;y--)if((a[x].first-lf)>>y){
				o=min(lcp[lf+1][y],lcp[a[x].first-(1<<y)+1][y]);break;
			}lf=a[x].first;
			for(;t&&o<=d[t];t--)tot[0]-=w[t][0]*d[t],al[0]+=w[t][0],tot[1]-=w[t][1]*d[t],al[1]+=w[t][1];
			d[++t]=o;
			w[t][0]=al[0];
			tot[0]+=o*al[0];
			w[t][1]=al[1];
			tot[1]+=o*al[1];
			ans+=tot[a[x].second^1];
		}
		cout<<ans<<endl;
	}
}