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
int getnum(){
    int r=0; bool ng=0; char c; c=_buff.get();
    while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
    if (c=='-') ng=1, c=_buff.get();
    while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
    return ng?-r:r;
}
set<string>pre;
set<string>suf;
set<string>used;
int n;
string s[2111];
vector<string> vec;
multiset<string>All,all;
bool check(string now){
	all=All;
	string tmp=now;
	//cout<<all.count("aba")<<endl;
	for(tmp.pop_back();tmp.size();tmp.pop_back()){
		cerr<<tmp<<endl;
		if(all.count(tmp)==0)return false;
		all.erase(all.find(tmp));
	}
	tmp=now;
	for(tmp.erase(tmp.begin());tmp.size();tmp.erase(tmp.begin())){
		cerr<<tmp<<endl;
		if(all.count(tmp)==0)return false;
		all.erase(all.find(tmp));
	}
	return true;
}
int main(){
	cin>>n;
	int len=0;
	for(int i=0;i<2*n-2;i++){
		cin>>s[i];
		All.insert(s[i]);
		if(s[i].size()>len)len=s[i].size();
	}
	for(int i=0;i<2*n-2;i++)if(s[i].size()==len)vec.push_back(s[i]);
	//cerr<<"ok"<<endl;
	//cerr<<vec[0]<<" "<<vec[1]<<endl;
	string now;
	//cerr<<vec[0]+vec[1].back()<<" "<<vec[1]+vec[0][0]<<endl;
	if(check(vec[0]+vec[1].back())){
		now=vec[0]+vec[1].back();
	}else{
		now=vec[1]+vec[0].back();
	}
	//cerr<<"ok"<<endl;
	string tmp=now;
	cerr<<now<<endl;
	for(tmp.pop_back();tmp.size();tmp.pop_back()){
		pre.insert(tmp);
	}
	tmp=now;
	for(tmp.erase(tmp.begin());tmp.size();tmp.erase(tmp.begin())){
		suf.insert(tmp);
	}
	for(int i=0;i<2*n-2;i++){
		//cerr<<s[i]<<" "<<pre.count(s[i])<<" "<<suf.count(s[i])<<endl;
		if(used.count(s[i])){
			putchar('P');
			continue;
		}
		if(suf.count(s[i])&&pre.count(s[i])){
			used.insert(s[i]);
			putchar('S');
		}else{
			if(suf.count(s[i]))putchar('S');
			else putchar('P');
		}
	}
	#ifndef ONLINE_JUDGE
		printf("\n-----\n");
        printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
    #endif
	return 0;
}