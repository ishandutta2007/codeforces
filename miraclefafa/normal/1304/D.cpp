#include <bits/stdc++.h>
using namespace std;
const int N=201000;
int mark[N],p[N],_,n;
char s[N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%s",&n,s);
		for (int i=0;i<n;i++) mark[i]=0;
		vector<int> ps;
		int len=1;
		for (int i=0;i<n;i++) {
			if (s[i]=='<') len++;
			else {
				ps.push_back(len);
				len=1;
			}
		}
		int m=n,pos=0;
		for (auto x:ps) {
			for (int j=0;j<x;j++) p[pos++]=m-x+1+j;
			m-=x;
		}
		for (int i=0;i<n;i++) printf("%d%c",p[i]," \n"[i==n-1]);
		int csmall=0;
		for (int i=1;i<n;i++) if (s[i-1]=='>') {
			mark[i]=1;
			csmall++;
		}
		int clarge=csmall+1;
		for (int i=0;i<n;i++) {
			if (mark[i]) p[i]=csmall--;
			else p[i]=clarge++;
		}
		for (int i=0;i<n;i++) printf("%d%c",p[i]," \n"[i==n-1]);
	}
}