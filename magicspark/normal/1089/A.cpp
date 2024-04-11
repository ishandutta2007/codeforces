//By MagicSpark
/*
Problem:1089A 
Main Idea:DP
Status:
*/
#include<bits/stdc++.h>
#pragma optimize("Ofast")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
//#include<ext/pb_ds/assoc_container.hpp>
#pragma comment(linker, "/STACK:16000000")
//#define map gp_hash_table
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
struct fastio{
    char s[100000];
    int it, len;
    fastio() {it=len=0;}
    inline char get(){
        if (it<len) return s[it++]; it=0;
        len=fread(s, 1, 100000, stdin);
        if (len==0) return EOF; else return s[it++];
    }
    bool notend(){
        char c=get();
        while (c==' '||c=='\n') c=get();
        if (it>0) it--;
        return c!=EOF;
    }
}_buff;
int getnum(){
    int r=0; bool ng=0; char c; c=_buff.get();
    while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
    if (c=='-') ng=1, c=_buff.get();
    while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
    return ng?-r:r;
}
struct game{
	bool ok;
	pair<int,int>pre;
}dp[410][410][4][4];
struct match{
	bool win;
	int a,b;
};
bool operator==(match a,match b){
	return a.a==b.a&&a.b==b.b;
}
game make(bool x,pair<int,int>p){
	return (game){x,p};
}
game make(bool x,int a,int b){
	return (game){x,make_pair(a,b)};
}
pair<int,int>null(-1,-1);
int mx[]={25,25,25,25,15};
vector<match>v[2];
match make(int a,int b){
	bool win=a>b;
	return (match){win,a,b};
}
void init(){
	for(int i=26;i<=200;i++)v[0].push_back(make(i,i-2)),v[0].push_back(make(i-2,i));
	for(int i=0;i<=23;i++)v[0].push_back(make(i,25)),v[0].push_back(make(25,i));
	for(int i=16;i<=200;i++)v[1].push_back(make(i,i-2)),v[1].push_back(make(i-2,i));
	for(int i=0;i<=13;i++)v[1].push_back(make(i,15)),v[1].push_back(make(15,i));
	//unique(v[0].begin(),v[0].end());
	//unique(v[1].begin(),v[1].end());
	//cout<<v[0].size()<<" "<<v[1].size()<<endl;
	dp[0][0][0][0]=make(true,null);
	int cnt=0;
	for(int a=0;a<=200;a++)
		for(int b=0;b<=200;b++)
			for(int wina=0;wina<=2;wina++)
				for(int winb=0;winb<=2;winb++)
					if(dp[a][b][wina][winb].ok){
						cnt++;
						//if(cnt%1000==0)cout<<cnt<<endl;
						//if(cnt>=47000)cout<<a<<" "<<b<<" "<<wina<<":"<<winb<<endl;
						int dat=(wina+winb)==4?1:0;
						for(int i=0;i<v[dat].size();i++){
							match mat=v[dat][i];
							if(a+mat.a>200||b+mat.b>200)continue;
							//if(cnt>=47000)cout<<"To:"<<a+mat.a<<" "<<b+mat.b<<" "<<wina+mat.win<<":"<<winb+1-mat.win<<endl;
							dp[a+mat.a][b+mat.b][wina+mat.win][winb+1-mat.win]=make(true,make_pair(a,b));
						}
					}
}
void print(int a,int b,int win,int lose){
	//cout<<a<<" "<<b<<" "<<win<<" "<<lose<<endl;
	game gm=dp[a][b][win][lose];
	if(gm.pre==null){
		return;
	}else{
		print(gm.pre.first,gm.pre.second,win-(a-gm.pre.first>b-gm.pre.second),lose-1+(a-gm.pre.first>b-gm.pre.second));
		printf("%d:%d ",a-gm.pre.first,b-gm.pre.second);
	}
	return;
}
void solve(int a,int b){
	for(int lose=0;lose<=2;lose++){
		if(dp[a][b][3][lose].ok){
			printf("3:%d\n",lose);
			print(a,b,3,lose);
			return;
		}
	}
	for(int win=2;win>=0;win--){
		if(dp[a][b][win][3].ok){
			printf("%d:3\n",win);
			print(a,b,win,3);
			return;
		}
	}
	puts("Impossible");
}
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		solve(a,b);
	}
	#ifndef ONLINE_JUDGE
		printf("\n-----\n");
        printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
    #endif
	return 0;
}