//By MagicSpark
/*
Problem:
Main Idea:
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
#define int long long
int getnum(){
    int r=0; bool ng=0; char c; c=_buff.get();
    while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
    if (c=='-') ng=1, c=_buff.get();
    while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
    return ng?-r:r;
}
int a,b,c,d,e,f;
int ans=INT_MAX,p1,p2;

int dis(int a,int b,int c,int d){
	return abs(a-c)+abs(b-d);
}

inline void print(int x,int y){
	if(x<p1) for(int i=x;i<p1;i++) printf("%I64d %I64d\n",i,y);
	else for(int i=p1+1;i<=x;i++) printf("%I64d %I64d\n",i,y);
	if(y<p2) for(int i=y;i<p2;i++) printf("%I64d %I64d\n",p1,i);
	else for(int i=p2+1;i<=y;i++) printf("%I64d %I64d\n",p1,i);
}

signed main(){
	a=getnum();b=getnum();c=getnum();d=getnum();e=getnum();f=getnum();
	for(int i=0;i<=1111;i++) for(int j=0;j<=1111;j++){
		int nd=dis(e,f,i,j)+dis(a,b,i,j)+dis(c,d,i,j);
		if(nd<ans){
			ans=nd;
			p1=i;
			p2=j;
		}
	}
	printf("%I64d\n",ans+1);
	print(a,b);
	print(c,d);
	print(e,f);
	printf("%I64d %I64d\n",p1,p2);
	return 0;
}