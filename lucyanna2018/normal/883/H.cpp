/*#### bits/stdc++.h */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
/*####*/
int cnt[128],n;
char s[444444],a[444444];int la;
int main(){
	scanf("%d%s",&n,s);
	for(int i=0; i<n; i++)
		cnt[s[i]]++;
	int mid = 0;
	for(int i=32; i<128; i++)
		if(cnt[i] % 2 == 1)
			mid ++;
	if(mid == 0){
		puts("1");
		int l = n/2;
		la=0;
		while(l--){
			int d;
			for(d = 32; cnt[d] < 2; d++);
			a[la++] = d;
			cnt[d] -=2;
		}
		for(int i=0; i<la; i++)printf("%c",a[i]);
		for(int i=la-1; i>=0; i--)printf("%c",a[i]);
		puts("");
		return 0;
	}
	while(n%mid!=0 || n/mid%2==0)mid++;
	printf("%d\n",mid);
	int len = n/mid;
	for(int run=0; run<mid; run++){
		int c = 32;
		while(c < 128 && cnt[c] % 2 == 0)c++;
		if(c == 128){
			c = 32;
			while(cnt[c] == 0)c++;
		}
		cnt[c] --;
		int l = n/mid/2;
		la=0;
		while(l--){
			int d;
			for(d = 32; cnt[d] < 2; d++);
			a[la++] = d;
			cnt[d] -= 2;
		}
		for(int i=0; i<la; i++)printf("%c",a[i]);printf("%c",c);
		for(int i=la-1; i>=0; i--)printf("%c",a[i]);
		if(run<mid-1)printf(" ");else
			printf("\n");
	}
	return 0;
}